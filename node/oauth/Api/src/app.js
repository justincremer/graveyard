const express = require("express");
const cookieSession = require("cookie-session");
const cors = require("cors");

const clickupService = require("./services/clickup.service");
const { httpsPort, client_id, cookie_secret } = require("./config/config");
const api_url = "https://localhost:" + httpsPort;

const app = express();

app.use(cookieSession({ secret: cookie_secret }));

app.use(cors());

app.use((req, res, next) => {
	res.header("Access-Control-Allow-Origin", "http://localhost:3000");
	res.header(
		"Access-Control-Allow-Methods",
		"GET, POST, OPTIONS, PUT, PATCH, DELETE",
	);
	res.header(
		"Access-Control-Allow-Headers",
		"Origin, X-Requested-With, content-type, Accept, Authorization",
	);
	res.header("Access-Control-Allow-Credentials", true);
	next();
});

app.get("/", (req, res, next) => {
	let content =
		(!req.session.loggedIn
			? '<a href="/login">login</a>'
			: req.session.username + ' <a href="/logout">logout</a>') +
		' <a href="/user">user</a>' +
		' <a href="/teamlist">teams</a>';

	res.send(content);
});

app.get("/ping", (req, res, next) => res.send("pong"));

app.get("/login", (req, res, next) => {
	const url =
		`https://app.clickup.com/api` +
		`?client_id=${client_id}&redirect_uri=${api_url}/login/callback`;

	res.redirect(url);
});

app.get("/login/callback", async (req, res, next) => {
	const code = req.query.code;
	const token = await clickupService.getAccessToken(code);
	const user = await clickupService.getUser(token);

	if (user) {
		req.session.loggedIn = true;
		// req.session.userId = user.id;
		req.session.username = user.username;
		req.session.token = token;

		// res.authToken = token;
		res.redirect("http://localhost:3000"); // for api testing, redirect here => "/"
	} else {
		res.status(404);
		res.send("Something went wrong");
	}
});

app.get("/auth", async (req, res, next) => res.send(req.session.token));

app.get("/logout", (req, res, next) => {
	if (req.session) {
		req.session = null;
		res.redirect("http://localhost:3000");
	} else res.send("Already logged out");
});

app.get("/user", async (req, res, next) => {
	const result = await clickupService.getUser(req.session.token);
	const body = JSON.stringify(result);
	res.send(body);
});

app.get("/teamlist", async (req, res, next) => {
	const result = await clickupService.getTeamlist(req.session.token);
	const body = JSON.stringify(result);
	res.send(body);
});

app.get("/team", async (req, res, next) => {
	const teamId = req.query.id;
	const result = await clickupService.getTeam(req.session.token, teamId);
	const content = result ? JSON.stringify(result) : "team not found ";

	res.send(content);
});

module.exports = app;

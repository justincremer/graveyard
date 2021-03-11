const clickupService = require("../services/clickup.service");
const { BASE_URL, CLIENT_ID } = require("../config/config");

const login = async () =>
	window.location.assign(
		`https://app.clickup.com/api` +
			`?client_id=${CLIENT_ID}&redirect_uri=${BASE_URL}`,
	);

const loginCallback = async (req, res) => {
	const code = req.query.code;
	const token = await clickupService.getAccessToken(code);

	if (token) {
		req.token = token;
		res.redirect("http://localhost:3000");
	} else {
		res.status(404);
		res.send("Something went wrong");
	}
};

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

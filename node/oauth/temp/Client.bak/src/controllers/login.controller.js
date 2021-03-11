const clickupService = require("../services/clickup.service");
const { BASE_URL, CLIENT_ID } = require("../config/config");

const login = async () =>
	window.location.assign(
		`https://app.clickup.com/api` +
			`?client_id=${CLIENT_ID}&redirect_uri=${BASE_URL}`,
	);

const getCodeFromCurrentUrl = async () => {
	const url = window.location.href;
	const getUrlVars = () => {
		var vars = {};
		var parts = url.replace(
			/[?&]+([^=&]+)=([^&]*)/gi,
			function (m, key, value) {
				vars[key] = value;
			},
		);
		return vars;
	};

	const code = getUrlVars()["code"];
	return code;
};

const loginCallback = async (req, res) => {
	const url = window.location.href;
	const code = req.query.code;
	const token = await clickupService.getAccessToken(code);

	if (token) {
		req.token = token;
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

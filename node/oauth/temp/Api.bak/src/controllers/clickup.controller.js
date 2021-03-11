const clickupService = require("../services/clickup.service");
const { httpsPort, user_id, client_id } = require("../configs/config");
const api_url = "localhost:" + httpsPort;

// Auth methods

function login(res, res, next) {
	const url =
		"https://app.clickup.com/api?client_id=" +
		client_id +
		"&redirect_uri=" +
		api_url +
		"/clickup/login/callback";

	console.log(url);

	res.redirect(url);
}

async function loginCallback(req, res, next) {
	const code = req.query.code;
	const token = await clickupService.getAccessToken(code);
	const user = await clickupService.getUser(token);

	if (user) {
		req.session.userId = user.id;
		req.session.username = user.username;
		req.session.token = token;

		res.redirect("/admin");
	} else {
		res.send("No teams were selected");
	}
}

function loginValidator(req, res) {
	if (req.session.userId === parseInt(user_id)) {
		res.send(
			"Hello, " +
				req.session.username +
				" :: " +
				JSON.stringify(req.session),
		);
	} else {
		res.send('Unauthorized access attempt, <a href="/login">login</a>');
	}
}

function logout(req, res) {
	req.session = null;
	res.redirect("/");
}

module.exports = {
	login,
	loginCallback,
	loginValidator,
	logout,
};

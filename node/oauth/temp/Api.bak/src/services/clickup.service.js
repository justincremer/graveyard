const fetch = require("node-fetch");
const { client_id, client_secret } = require("../configs/config");

async function getAccessToken(code) {
	const result = await fetch("https://app.clickup.com/api/v2/oauth/token", {
		method: "POST",
		headers: {
			"Content-Type": "application/json",
		},
		body: JSON.stringify({ client_id, client_secret, code }),
	});

	const data = await result.json();
	const params = new URLSearchParams(data);
	return params.get("access_token");
}

async function getUser(accessToken) {
	const result = await fetch("https://app.clickup.com/api/v2/user", {
		headers: {
			Authorization: accessToken,
		},
	});

	const data = await result.json();
	return data.user;
}

async function getTeams(accessToken) {
	const result = await fetch("https://app.clickup.com/api/v2/team", {
		headers: {
			Authorization: accessToken,
		},
	});

	const data = await result.json();
	return data;
}

module.exports = {
	getAccessToken,
	getUser,
	getTeams,
};

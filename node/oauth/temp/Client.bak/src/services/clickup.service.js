const { CLIENT_ID, CLIENT_SECRET } = require("../config/config");

async function getAccessToken(code) {
	const result = await fetch("https://app.clickup.com/api/v2/oauth/token", {
		method: "POST",
		headers: {
			"Content-Type": "application/json",
		},
		body: JSON.stringify({ CLIENT_ID, CLIENT_SECRET, code }),
	});

	const data = await result.json();
	const params = new URLSearchParams(data);
	return params.get("access_token");
}

async function getUser(accessToken) {
	const result = await fetch("https://app.clickup.com/api/v2/user", {
		headers: { Authorization: accessToken },
	});
	const data = await result.json();
	return data.user;
}

async function getTeamlist(accessToken) {
	var result = await fetch("https://app.clickup.com/api/v2/team", {
		headers: { Authorization: accessToken },
	});
	const data = await result.json();
	return data.teams;
}

async function getTeam(accessToken, teamId) {
	const teamlist = await getTeamlist(accessToken);

	for (let i = 0; i < teamlist.length; i++) {
		if (teamlist[i] === teamId) return teamlist[i];

		return null;
	}
}

// Once authentication is pushed into a controller, replace boolean returns with authentication method,
// given an individual is not authenticated.
/* const ensureAuthenticated = (compId, userId = null) => {
	const authenticated = (id) => (compId === parseInt(id) ? true : false);

	if (userId) return authenticated(userId);
	else if (current_user_id) return authenticated(current_user_id);
	else throw Error("You aren't signed in");
}; */

module.exports = {
	getAccessToken,
	getUser,
	getTeamlist,
	getTeam,
	// ensureAuthenticated,
};

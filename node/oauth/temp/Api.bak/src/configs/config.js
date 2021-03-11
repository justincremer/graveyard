const httpPort = process.env.API_HTTP_PORT || 3000;
const httpsPort = process.env.API_HTTPS_PORT || 3443;

const user_id = process.env.CLICKUP_USER_ID;
const client_id = process.env.CLICKUP_CLIENT_ID;
const client_secret = process.env.CLICKUP_CLIENT_SECRET;

const cookie_secret = process.env.COOKIE_SECRET;

module.exports = {
	httpPort,
	httpsPort,
	user_id,
	client_id,
	client_secret,
	cookie_secret,
};

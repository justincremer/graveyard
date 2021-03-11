const https = require("https");

const { sslCreds } = require("./configs/openssl");
const { httpsPort } = require("./configs/config");
const app = require("./app");

const server = https.createServer(sslCreds, app);

server.listen(httpsPort, () =>
	console.log("Listening on https://localhost:" + httpsPort),
);

const exitHandler = () => {
	if (server) {
		server.close(() => {
			console.log("Server closed");
			process.exit(1);
		});
	} else {
		process.exit(1);
	}
};

const unexpectedErrorHandler = (error) => {
	console.log("Error: " + error.message);
	exitHandler();
};

process.on("uncaughtException", unexpectedErrorHandler);
process.on("unhandledRejection", unexpectedErrorHandler);

process.on("SIGTERM", () => {
	logger.info("SIGTERM received");
	if (server) {
		server.close();
	}
});

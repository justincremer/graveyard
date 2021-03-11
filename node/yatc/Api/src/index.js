const mongoose = require("mongoose");
const app = require("./app");
const { baseConfig, morganConfig } = require("./config");

let server;
mongoose
	.connect(baseConfig.mongoose.url, baseConfig.mongoose.options)
	.then(() => {
		loggerConfig.info("Connected to MongoDB");
		server = app.listen(config.port, () => {
			loggerConfig.info(`Listening to port ${config.port}`);
		});
	});

const exitHandler = () => {
	if (server) {
		server.close(() => {
			loggerConfig.info("Server closed");
			process.exit(1);
		});
	} else {
		process.exit(1);
	}
};

const unexpectedErrorHandler = (error) => {
	loggerConfig.error(error);
	exitHandler();
};

process.on("uncaughtException", unexpectedErrorHandler);
process.on("unhandledRejection", unexpectedErrorHandler);

process.on("SIGTERM", () => {
	loggerConfig.info("SIGTERM received");
	if (server) {
		server.close();
	}
});

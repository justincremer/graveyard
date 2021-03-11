const morgan = require("morgan");
const { baseConfig, loggerConfig } = require(".");

morgan.token("message", (req, res) => res.locals.errorMessage || "");

const getIpFormat = () =>
	baseConfig.env === "production" ? ":remote-addr - " : "";
const successResponseFormat = `${getIpFormat()}:method :url :status - :response-time ms`;
const errorResponseFormat = `${getIpFormat()}:method :url :status - :response-time ms - message: :message`;

const successHandler = morgan(successResponseFormat, {
	skip: (req, res) => res.statusCode >= 400,
	stream: { write: (message) => loggerConfig.info(message.trim()) },
});

const errorHandler = morgan(errorResponseFormat, {
	skip: (req, res) => res.statusCode < 400,
	stream: { write: (message) => loggerConfig.error(message.trim()) },
});

module.exports = {
	successHandler,
	errorHandler,
};

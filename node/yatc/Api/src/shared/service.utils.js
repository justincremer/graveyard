const catchAsync = (method) => (req, res, next) => {
	Promise.resolve(method(req, res, () => next()).catch((err) => next(err)));
};

const ensureSuccess = (dbo) => {
	if (dbo.statusCode < 200 || dbo.statusCode >= 300)
		throw Error("Error resolving request");
};

/**
 * Create an object composed of the picked object properties
 * @param {Object} object
 * @param {string[]} keys
 * @returns {Object}
 */
const pick = (object, keys) => {
	return keys.reduce((obj, key) => {
		if (object && Object.prototype.hasOwnProperty.call(object, key))
			// eslint-disable-next-line no-param-reassign
			obj[key] = object[key];
		return obj;
	}, {});
};

/**
 * @typedef ApiError
 */
class ApiError extends Error {
	constructor(statusCode, message, isOperational = true, stack = "") {
		super(message);
		this.statusCode = statusCode;
		this.isOperational = isOperational;
		if (stack) {
			this.stack = stack;
		} else {
			Error.captureStackTrace(this, this.constructor);
		}
	}
}

module.exports = {
	catchAsync,
	ensureSuccess,
	pick,
	ApiError,
};

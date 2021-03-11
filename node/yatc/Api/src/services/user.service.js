const httpStatus = require("http-status");
const { userModel } = require("../models");
const { ApiError } = require("../shared/service.utils");

/**
 * Create a user
 * @param {Object} userBody
 * @returns {Promise<User>}
 */
const create = async (userBody) => {
	if (await userModel.isEmailTaken(userBody.email))
		throw new ApiError(
			httpStatus.BAD_REQUEST,
			`Email address "${userBody.email}" is already in use`,
		);

	const result = await userModel.create(userBody);
	return result;
};

/**
 * Query for users
 * @param {Object} filter - Mongo filter
 * @param {Object} options - Query options
 * @param {string} [options.sortBy] - Sort option in the format: sortField:(desc|asc)
 * @param {number} [options.limit] - Maximum number of results per page (default = 10)
 * @param {number} [options.page] - Current page (default = 1)
 * @returns {Promise<QueryResult>}
 */
const query = async (filter, options) => {
	const users = await userModel.paginate(filter, options);
	return users;
};

/**
 * Get user by id
 * @param {ObjectId} id
 * @returns {Promise<User>}
 */
const getById = async (id) => {
	return userModel.findById(id);
};

/**
 * Get user by email
 * @param {string} email
 * @returns {Promise<User>}
 */
const getByEmail = async (email) => {
	return userModel.findOne({ email });
};

/**
 * Update user by id
 * @param {ObjectId} userId
 * @param {Object} updateBody
 * @returns {Promise<User>}
 */
const updateById = async (userId, updateBody) => {
	const user = await getUserById(userId);
	if (!user) {
		throw new ApiError(httpStatus.NOT_FOUND, "User not found");
	}
	if (
		updateBody.email &&
		(await User.isEmailTaken(updateBody.email, userId))
	) {
		throw new ApiError(httpStatus.BAD_REQUEST, "Email already taken");
	}
	Object.assign(user, updateBody);
	await user.save();
	return user;
};

/**
 * Remove user by id
 * @param {ObjectId} userId
 * @returns {Promise<User>}
 */
const removeById = async (userId) => {
	const user = await getUserById(userId);
	if (!user) {
		throw new ApiError(httpStatus.NOT_FOUND, "User not found");
	}
	await user.remove();
	return user;
};

/**
 * @typedef UserService
 */
module.exports = {
	create,
	query,
	getById,
	getByEmail,
	updateById,
	removeById,
};

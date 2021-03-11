const httpStatus = require("http-status");
const { userService } = require("../services");
const { ApiError, catchAsync, pick } = require("../shared/service.utils");

const create = catchAsync(async (req, res) => {
	const user = await userService.create(req.body);
	res.status(httpStatus.CREATED);
	res.send(user);
});

const list = catchAsync(async (req, res) => {
	const filter = pick(req.query, ["name", "role"]);
	const options = pick(req.query, ["sortBy", "limit", "page"]);
	const result = await userService.query(filter, options);
	res.send(result);
});

const get = catchAsync(async (req, res) => {
	const user = await userService.getById(req.params.userId);
	if (!user) throw new ApiError(httpStatus.NOT_FOUND);
	res.send(user);
});

const update = catchAsync(async (req, res) => {
	const user = await userService.updateById(req.params.userId, req.body);
	res.send(user);
});

const remove = catchAsync(async (req, res) => {
	await userService.removeById(req.params.userId);
	res.status(httpStatus.NO_CONTENT).send();
});

module.exports = { create, list, get, update, remove };

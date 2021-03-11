import { randomInt } from "crypto";
import { v4 as uuidv4 } from "uuid";

const generateId = () => uuidv4();

const generateRandomString = (
	size,
	spacesFlag = false,
	numbersFlag = false,
	symbolsFlag = false,
) => {
	const space = " ";
	const numbers = "1234567890";
	const symbols = "!#$%^&*_+";

	let charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (spacesFlag === true) charSet += space;
	if (numbersFlag === true) charSet += numbers;
	if (symbolsFlag === true) charSet += symbols;

	let result = "";
	for (let i = 0; i < size; i++)
		result += charSet[randomInt(0, charSet.length)];

	return result;
};

const generateRandomEmail = (size, domain) => {
	if (domain.includes(" ")) throw Error("Invalid domain");

	return `${generateRandomString(size, false, true, false)}@${domain}.com`;
};

const generateFakeUser = () => {
	const email = generateRandomEmail(8, "mutt");

	return {
		firstName: email,
		lastName: email,
		email: email,
		password: generateRandomString(8) + "123!",
		age: 22,
	};
};

module.exports = {
	generateId,
	generateRandomString,
	generateRandomEmail,
	generateFakeUser,
};

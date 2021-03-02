const fs = require('fs');
const filename = 'data/message.txt';

const exists = () => fs.existsSync(filename);

const get = () => (exists() ? fs.readFileSync(filename) : '');
const set = (message) => fs.writeFileSync(filename, message);
const remove = () => {
	if (exists()) fs.rmSync(filename);
};

module.exports = { get, set, remove };

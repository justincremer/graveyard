const axios = require('axios');
const crypto = require('crypto');
const _ = require('lodash');
const fs = require('fs');

/*
  Note: I'm uncertain how to format my data based on the instructions and am not getting the correct checksum.
  I don't know if i'm supposed to be filtering results based on the age 32, if I should put a space or a comma
  between the key and value, etc.  These are not made clear and the tests will not pass as a result,
  though I hope my code is clean enough to make sense.
*/

class Person {
	constructor(key, age) {
		this.key = key;
		this.age = age;
	}

	fmt = () => `${this.key} ${this.age}\n`;		
}

// removes whitespace, splits on ',', gets only the necessary data, and then groups into pairs of two
const arrange = (str) =>
	  _.chunk(str.replace(/\s+/g, '').split(',').map(i => i.substr(4)), 2);

// creates an array of people from an array of kvps
const peopleFromPairs = (pairs) =>
	  pairs.map(p => new Person(p[0], p[1])).filter(p => p.age == "32");

// composes the ladder two functions
const deserialize = (data) =>
	  peopleFromPairs(arrange(data));

// formats data accoring to specs ???
const formatData = (people) =>
	  people.map(p => p.fmt()).join('');

// saves a buffer to disk
const write = (buf, path) =>
	  fs.writeFile(path, `${buf}\n`, (err) => {
		  if (err) {
			  console.error(`failed to write file, error: ${e}`);
		  }
	  });

// loads a file, composing and logging the provided callback method over the resulting data
const onRead = (path, callback) =>
	  fs.readFile(path, 'utf8', (err, data) => {
		  if (err) {
			  console.error(`failed to read file, error: ${e}`);
		  }
		  console.log(callback(data));
	  });

// produce a sha1 checksum from a byte stream
function checksum(buf) {
	let shasum = crypto.createHash('sha1');
	shasum.update(buf);
	return shasum.digest('hex');
}

axios.get('https://coderbyte.com/api/challenges/json/age-counting')
	.then(res => {
		const path = "output.txt";
		let buf = formatData(deserialize(res.data.data));
		write(buf, path);
		onRead(path, checksum);
	});


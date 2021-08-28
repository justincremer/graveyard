type constraint = (c: string) => boolean;

const isUpper = (c: string): boolean => c === c.toUpperCase();
const isNum = (c: string): boolean => RegExp(/^[0-9]+$/).test(c);
const isSymbol = (c: string): boolean => RegExp(/[-!$%^&*()_+|~=`{}\[\]:";'<>?,.\/]/).test(c);

// Where any is the signature of a function that takes a character and returns boolean
const newFlagMap = (): Map<constraint, boolean> => new Map()
	.set(isUpper, false)
	.set(isNum, false)
	.set(isSymbol, false);

// check contains 'password'
// check 7 < password > 31

function StringChallenge(str: string): string {
	let flags: Map<constraint, boolean> = newFlagMap();
	str.split("").forEach(c => {
		flags.forEach((flag, callback) => {
			if (!flag) {
				if (callback(c)) {
					flags.set(callback, true);
				}
			}
		});
	});

	// Apply mask over constraint method results to check if they are all valid
	let valid = true;
	flags.forEach((flag, _) => valid = valid && flag);
	if (!valid) {
		return "false"
	}

	return valid && str.length > 7 && str.length < 31 && !str.toLowerCase().includes("password") ?
		"true" :
		"false";
}

// keep this function call here
// @ts-ignore
console.log(StringChallenge(readline()));

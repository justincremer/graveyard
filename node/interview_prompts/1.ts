// import { readLines } from 'https://deno.land/std@0.82.0/io/bufio.ts'

const shiftChar = (c: string): string =>
	String.fromCharCode(c.charCodeAt(0) + 1);

// Shifts and uppercases vowels
const complexShift = (c: string): string => {
	c = c === 'z' ? 'a' : shiftChar(c);
	return 'aeiou'.includes(c) ? c.toUpperCase() : c;
}

function StringChallenge(str: string): string {
		const regex = RegExp(/^[a-z]#$/);
		const iter = str.toLowerCase().split("");
		return iter.map(c => regex.test(c) ? complexShift(c) : c).join("");
}

// keep this function call here
// @ts-ignore
console.log(StringChallenge(readline()));

// Parse stdio in Deno
// console.log(StringChallenge(readLines(Deno.stdin)));

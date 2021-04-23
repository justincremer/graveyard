/**
 * You are given incomplete code below and your task is to complete it.
 * Read thru each problem carefully and follow the instructions.
 *
 * Have fun coding!!!
 */

const peopleData = `
    mary,2001-01-02,27518
    john,1997-05-03,75001
    sam,1999-05-04,90210
    jim,1999-05-09,75043
`;

const zipcodesData = `
    90210,CA
    75001,TX
    27518,NC
`;
/** !!!DO NOT CHANGE ANYTHING ABOVE THIS LINE!!! */

/**
 * Problem 1:
 *  Given a defined `peopleData` (string),
 *  complete the code below so it yields the expected `people` (object).
 *
 *  Follow instructions as stated in the in-line comments
 *
 * Expected:
 *  [
 *    {name: 'mary', dob: '2001-01-02', zip: '27518'},
 *    {name: 'john', dob: '1997-05-03', zip: '75001'},
 *    {name: 'sam',  dob: '1999-05-04', zip: '90210'},
 *    {name: 'jim',  dob: '1999-05-09', zip: '75043'}
 *  ]
 */

const people = peopleData
  .split("\n")
  .filter((p) => p !== "")
  .map((p) => p.split(","))
  .map((item) => Object({ name: item[0].trim(), dob: item[1], zip: item[2] }));

console.log("Problem 1:");
console.log(people);
console.log();

/**
 * Problem 2:
 *  Given a defined `zipcodesData` (string),
 *    complete the code below so it yields the expected `zipcodes` (object).
 *
 * Expected:
 *  { '75001': 'TX', '90210': 'CA' }
 */

const fold = (hmap, zip, state) => {
  hmap[zip] = state;
  return hmap;
};

const zipcodes = zipcodesData
  .split("\n")
  .filter((item) => item !== "" && !item.includes("NC"))
  .map((item) => item.split(","))
  .reduce((acc, item) => fold(acc, item[0].trim(), item[1]), {});

console.log("Problem 2:");
console.log(zipcodes);
console.log();

/**
 * After completing the scripts above,
 *    execute your code to see the `console.log` output.
 *
 * Problem 3:
 *  If both `people` and `zipcodes` data were pulled from a DB,
 *    Write an equivalent `SQL SELECT` statement into
 *      the space inside the comment below.
 *
 * Note: I'm not entirely sure what the hypothetical schema is,
 *  so I'm going to make the assumption that a given zipcode
 *  contains a value column equal to it's zipcode.  I'm going to
 *  compare our filtered people table and join on that field
 *  being equal to a zipcode's value field.  I'll format it as a
 *  postgres query.
 *
 *  <SELECT *
 *      FROM people AS p
 *      WHERE dob >= '1999-01-01'
 *      JOIN zipcodes AS z
 *      ON p.zip = z.id;>
 */

console.log("Problem 3:");
people.forEach((p) => {
  if (p.dob >= "1999-01-01") {
    console.log(p.name, p.dob, p.zip, zipcodes[p.zip] ?? "");
  }
});
console.log();

/**
 * Problem 4:
 *  After completing Problems 1 and 2,
 *    implement the recursive `groupByDobYearMonth` function.
 *  The `console.log` line at the bottom, upon calling your function,
 *    must generate the following output:
 *
 * Expected:
 *  {
 *    "2001-01": [
 *      {
 *        "name": "mary",
 *        "dob": "2001-01-02",
 *        "zip": "27518"
 *      }
 *    ],
 *    "1997-05": [
 *      {
 *        "name": "john",
 *        "dob": "1997-05-03",
 *        "zip": "75001"
 *      }
 *    ],
 *    "1999-05": [
 *      {
 *        "name": "sam",
 *        "dob": "1999-05-04",
 *        "zip": "90210"
 *      },
 *      {
 *        "name": "jim",
 *        "dob": "1999-05-09",
 *        "zip": "75043"
 *      }
 *    ]
 *  }
 */

// Merge takes in a list of people and a new person and checks if the person's dob is present in the list
// as a key.  If it is, that key's associated array will have the person appended to it.  A new kvp will
// otherwise be appended to the list, the value in this case being a new array containing only the person.
const merge = (list, person) => {
  const curr = person;
  const key = curr["dob"].slice(0, -3);

  if (list === null || list === undefined) {
    list[key] = [curr];
    return list;
  }

  if (Object.keys(list).includes(key)) {
    list[key].push(curr);
    return list;
  }

  list[key] = [curr];
  return list;
};

// Takes a list of people, checks if the list is nil, and if so, returns an empty list.
// Otherwise, checks if the list contains only one element and if so, returns an object
// containing only a kvp, with the year and month as the key and the person in a list as
// the value.  If the list contains more that one element, groupByDobYearMonth is called
// recursivley within a merge, the new people list (list) having the final element omitted,
// and the person (person) being that final person.
function groupByDobYearMonth(people) {
  if (people === null || people === undefined) return {};

  const len = people.length;
  return len === 1
    ? merge({}, people[0])
    : merge(groupByDobYearMonth(people.slice(0, len - 1)), people[len - 1]);
}

console.log("Problem 4:");
console.log(JSON.stringify(groupByDobYearMonth(people), null, 2));
console.log();

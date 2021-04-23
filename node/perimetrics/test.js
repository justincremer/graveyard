const peopleData = `
    mary,2001-01-02,27518
    john,1997-05-03,75001
    sam,1999-05-04,90210
    jim,1999-05-09,75043
`;

const people = peopleData
  .split("\n")
  .filter((p) => p != "")
  .map((p) => p.split(","))
  .map((item) => Object({ name: item[0].trim(), dob: item[1], zip: item[2] }));

/*  [
 *    {name: 'mary', dob: '2001-01-02', zip: '27518'},
 *    {name: 'john', dob: '1997-05-03', zip: '75001'},
 *    {name: 'sam',  dob: '1999-05-04', zip: '90210'},
 *    {name: 'jim',  dob: '1999-05-09', zip: '75043'}
 *  ]
 */

const merge = (list, person) => {
  const curr = person;
  const date = curr["dob"];
  const key = date.slice(0, -3);

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

const groupByDobYearMonth = (people) => {
  const len = people.length;

  return len === 1
    ? merge({}, people[0])
    : merge(groupByDobYearMonth(people.slice(0, len - 1)), people[len - 1]);
};

/* Expected:
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

console.log(JSON.stringify(groupByDobYearMonth(people), null, 2));

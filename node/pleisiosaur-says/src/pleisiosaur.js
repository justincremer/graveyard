const fs = require("fs");

const fileToString = (filename) => fs.readFileSync(filename).toString();

const logWS = (n) => {
  for (i = 0; i < n; i++) console.log();
};

const generateTextBox = (text) => {
  let top = "\t ",
    middle = `\t| ${text} |`,
    bottom = "\t ";

  for (let i = 0; i < text.length + 2; i++) {
    top += "-";
    bottom += "-";
  }

  top += " \n";
  middle += "\n";
  bottom += " \n";

  return top + middle + bottom;
};

const pleisiosaurSays = (text) => {
  const textBox = generateTextBox(text);
  const pleisiosaur = fileToString(process.cwd() + "/pleisiosaur.md");

  logWS(20);
  console.log(textBox + pleisiosaur);
  logWS(5);
};

module.exports = {
  pleisiosaurSays,
};

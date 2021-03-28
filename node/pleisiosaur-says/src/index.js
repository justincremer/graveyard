const {pleisiosaurSays} = require('./pleisiosaur');

const message = process.argv[2];

if (message === undefined || message === "") {
    console.log("You must provide a message");
    process.exit(1);
}

pleisiosaurSays(message);
// "Tryna play some valorant?"
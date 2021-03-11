const url = 'mongodb://localhost:27017/';
const database = 'test';
const connectionParameters = {
    useNewUrlParser: true,
    useUnifiedTopology: true,
};

module.exports = {
    url,
    database,
    connectionParameters,
};

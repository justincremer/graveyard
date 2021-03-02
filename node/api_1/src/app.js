const express = require('express');
const router = require('./routes/router.js');
const { logger, static, bodyParser } = require('./middleware/mod.js');

const PORT = 8000;
const app = express();

app.set('view engine', 'pug');
app.set('views', 'src/views');

app.use(bodyParser);
app.use(static);
app.use(logger);

app.use(router);

app.listen(PORT);

console.log(`Listening on http://localhost:${PORT}`);

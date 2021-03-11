const express = require("express");
const routes = require("./routes/clickup.routes");
const cookieSession = require("cookie-session");
const { cookie_secret } = require("./configs/config");

const app = express();

app.use(cookieSession({ secret: cookie_secret }));

app.get("/", (req, res, next) => res.send("HomePage"));

app.use("/clickup", routes);

module.exports = app;

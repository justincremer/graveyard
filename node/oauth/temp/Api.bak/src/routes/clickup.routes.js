const clickupController = require("../controllers/clickup.controller");
const express = require("express");

const router = express.Router();

router.route("/login").get(() => clickupController.login());
router.route("/login/callback").get(() => clickupController.loginCallback());
router.route("/logout").get(() => clickupController.logout());
router.route("/admin").get(() => clickupController.loginValidator());

module.exports = router;

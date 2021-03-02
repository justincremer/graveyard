const express = require('express');
const path = require('path');
const rootDir = require('../utils/path');

const router = express.Router();

const adminRoutes = require('./admin.js');
const shopRoutes = require('./shop.js');

router.use('/admin', adminRoutes);
router.use('/shop', shopRoutes.router);
router.use((req, res, next) =>
	res.status(404).sendFile(path.join(rootDir, 'views', 'page-not-found.html'))
);

module.exports = router;

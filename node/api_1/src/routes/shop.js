const express = require('express');
const path = require('path');
const rootDir = require('../utils/path');

const router = express.Router();

const products = [];

router
	.get('/favicon.ico', (req, res) => res.sendStatus(204))
	.get('/', (req, res) => {
		res.render('shop/shop', { pageTitle: 'Shop', products: products });
	})
	.get('/add-product', (req, res) => {
		res.render('shop/add-product', {
			pageTitle: 'Add Product',
		});
	})
	.post('/add-product', (req, res) => {
		const title = req.body.title;
		products.push({ title: title });
		res.redirect('/shop');
	});

module.exports = { router, products };

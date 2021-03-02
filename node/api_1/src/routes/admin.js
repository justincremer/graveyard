const express = require('express');
const message = require('../controllers/message.js');

const router = express.Router();

router
	.get('/', (req, res) => res.send('<h2>pogChamp</h2>'))
	.get('/message', (req, res) => {
		const result = message.get();
		res.send(`<h2>${result}</h2>`);
	})
	.get('/message/clear', (req, res) => {
		message.remove();
		res.redirect('/admin');
	})
	.delete('/message', (req, res) => message.remove())
	.post('/message', (req, res) => {
		const result = req.headers['message'];
		message.set(result);
		res.end();
	});

module.exports = router;

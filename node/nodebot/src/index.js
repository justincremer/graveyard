const { Client, EVENT } = require('dogehouse.js');
require('dotenv').config();

const { DOGEHOUSE_TOKEN, DOGEHOUSE_REFRESH_TOKEN } = process.env;

const app = new Client();
app.connect(DOGEHOUSE_TOKEN, DOGEHOUSE_REFRESH_TOKEN).then(async () =>
	console.log('Bot connected!')
);

app.on(EVENT.NEW_CHAT_MESSAGE, (message) => {
	const content = message.content;

	if (content.includes('nodebot.interpret("')) {
		try {
			// const call = content.slice(19, -2);
			// const result = eval(call);

			message.reply('hello world');
			// console.log(result);
		} catch (e) {
			console.log(e);
		}
	}
});

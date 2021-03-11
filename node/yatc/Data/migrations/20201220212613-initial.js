module.exports = {
	async up(db, client) {
		await db.createCollection("blogs");
		await db.collection("blogs").updateMany({}, { $set: { quantity: 10 } });
	},

	async down(db, client) {
		await db
			.collection("blogs")
			.updateMany({}, { $unset: { quantity: null } });
	},
};

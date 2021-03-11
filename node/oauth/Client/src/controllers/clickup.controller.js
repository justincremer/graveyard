app.get("/user", async (req, res, next) => {
	const result = await clickupService.getUser(req.session.token);
	const body = JSON.stringify(result);
	res.send(body);
});

app.get("/teamlist", async (req, res, next) => {
	const result = await clickupService.getTeamlist(req.session.token);
	const body = JSON.stringify(result);
	res.send(body);
});

app.get("/team", async (req, res, next) => {
	const teamId = req.query.id;
	const result = await clickupService.getTeam(req.session.token, teamId);
	const content = result ? JSON.stringify(result) : "team not found ";

	res.send(content);
});

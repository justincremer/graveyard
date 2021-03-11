import React, { useState } from "react";
import { Button, Container, Row, Col } from "reactstrap";

import "./App.css";

const baseApiUrl = `https://localhost:3443`;

const App = () => {
	const [authToken, setAuthToken] = useState(null);
	const [user, setUser] = useState(null);
	const [teamlist, setTeamlist] = useState(null);

	const [text, setText] = useState("");
	const getPing = async () =>
		fetch(baseApiUrl + "/ping")
			.then((response) => response.text())
			.then((data) => setText(data))
			.catch((error) => console.error("Error: ", error));

	// Clickup authorization :: methods for authenticating with clickup's api

	const authHeaders = async () =>
		authToken ? { headers: { session: { token: authToken } } } : {};

	async function Login() {
		window.location.href = baseApiUrl + "/login";
	}

	async function loginHandler() {
		Login().then(
			fetch(baseApiUrl + "/auth")
				.then((response) => response.text())
				.then((data) => setAuthToken(data))
				.catch((error) => console.error("Error: ", error)),
		);
	}

	async function Logout() {
		window.location.href = baseApiUrl + "/logout";
	}

	async function logoutHandler() {
		Logout()
			.then(() => setAuthToken(null))
			.catch((error) => console.error("Error: ", error));
	}

	// Clickup getters :: methods for retreiving information from clickup's api

	async function getUserInfo() {
		fetch(baseApiUrl + "/user", authHeaders())
			.then((response) => response.text())
			.then((data) => setUser(data ? JSON.parse(data) : {}))
			.catch((error) => console.error("Error: ", error));
	}

	async function getTeamlist() {
		await fetch(baseApiUrl + "/teamlist", authHeaders())
			.then((response) => response.text())
			.then((data) => setTeamlist(data ? JSON.parse(data) : {}))
			.catch((error) => console.error("Error: ", error));
	}

	return (
		<div className="App">
			<header className="App-Top-Panel">
				<Container>
					<Row>
						<Col sm="2" lg={{ size: 2, offset: 1 }}>
							<h1>ClickUp Enumerator</h1>
							<h4>(practice project)</h4>
						</Col>
						<Col sm="2" lg={{ size: 2, offset: 1 }}>
							<p>test</p>
						</Col>
					</Row>
				</Container>
			</header>

			<header className="App-Buttons">
				<Button onClick={loginHandler}>Login</Button>
				<Button onClick={logoutHandler}>Logout</Button>
				<Button onClick={getPing}>Ping</Button>
				<Button onClick={getUserInfo}>User Info</Button>
				<Button onClick={getTeamlist}>Teamlist</Button>
			</header>
			<header className="App-Textbox">
				<h3>Auth Token</h3>
				<p>{authToken}</p>
			</header>
			<header className="App-Textbox">
				<h3>Ping?</h3>
				<p>{text}</p>
			</header>
			<header className="App-Textbox">
				<h3>User</h3>
				<p>{JSON.stringify(user)}</p>
			</header>
			<header className="App-Textbox">
				<h3>Team List</h3>
				<p>{JSON.stringify(teamlist)}</p>
			</header>
		</div>
	);
};

export default App;

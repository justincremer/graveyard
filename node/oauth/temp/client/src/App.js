import React from "react";
import "./App.css";
import { BrowserRouter as Router, Route } from "react-router-dom";

const Home = () => <h1>Home</h1>;
const LoginCallback = () => <h1>Login Callback</h1>;

const App = () => (
	<Router>
		<h1>Working...</h1>
		<Route path="/home" component={Home} />
		<Route path="/loginCallback" component={LoginCallback} />
	</Router>
);

export default App;

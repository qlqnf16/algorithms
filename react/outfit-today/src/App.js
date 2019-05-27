import React from "react";
import { Route, Router, Switch } from "react-router-dom";
import "./App.css";

import Home from "./pages/Home";

const App = () => {
  <Router>
    <Switch>
      <Route exact path="/" component={Home} />
    </Switch>
  </Router>;
};

export default App;

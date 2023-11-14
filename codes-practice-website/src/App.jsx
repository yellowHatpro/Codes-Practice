import "./App.css";
import Navbar from "./components/Navbar/Navbar.jsx";
import Footer from "./components/Footer/Footer.jsx";
import Directories from "./pages/dir/Directories.jsx";
import {BrowserRouter as Router, Routes, Route } from "react-router-dom";
import { useState } from "react";
import {gh_url, handleBackPress} from "./utils.js";

function App() {
    const [path, setPath] = useState([])
    const [url, setUrl] = useState(gh_url);
    return (
        <div className="App">
            <Router>
                <div className={"app-content"}>
                    <Navbar path={path} handleBackPress={() => handleBackPress(path, setPath, setUrl)}/>
                    <div className="container">
                        <Routes>
                            <Route path="/"
                                   element=
                                       {<Directories
                                           url={url}
                                           setUrl={setUrl}
                                           path={path}
                                           setPath={setPath}/>}/>
                            <Route path="*" element={"404 Not Found"}/>
                        </Routes>
                    </div>
                    <Footer/>
                </div>
            </Router>
        </div>
    );
}

export default App;

import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import Directories from "./pages/dir/Directories";
import {BrowserRouter as Router, Routes, Route } from "react-router-dom";
import { useState } from "react";

function App() {
    const [path, setPath] = useState([])
    const [url, setUrl] = useState("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/?ref=master");
    return (
        <div className="App">
            <Router>
                <Navbar/>
                <div className="container">
                    <Routes>
                        <Route path="/" element={<Directories url={url} setUrl={setUrl} path={path} setPath={setPath}/>}/>
                        <Route path="*" element={"404 Not Found"}/>
                    </Routes>
                </div>
                <Footer/>
            </Router>
        </div>
    );
}

export default App;

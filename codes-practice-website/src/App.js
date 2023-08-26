import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import Directories from "./pages/dir/Directories";
import {BrowserRouter as Router, Routes, Route } from "react-router-dom";

function App() {
    return (
        <div className="App">
            <Router>
                <Navbar/>
                <div className="container">
                    <Routes>
                        <Route path="/" element={<Directories/>}>
                          <Route path="*" element={"404 Not Found"}/>
                        </Route>
                    </Routes>
                </div>
                <Footer/>
            </Router>
        </div>
    );
}

export default App;

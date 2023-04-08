import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import Directories from "./data/main/Directories";
import {BrowserRouter as Router, Routes, Route} from "react-router-dom";

function App() {
    return (
        <div className="App">
            <Router>
                <Navbar/>
                <div className="container">
                    <Routes>
                        <Route exact path="/" element={<Directories/>}>
                            <Route path=":name/" element={<Directories/>}>
                                <Route path=":name1/*" element={<Directories/>}/>
                            </Route>
                            <Route path="*" element={"Work In Progress"}/>
                        </Route>
                    </Routes>
                </div>
                <Footer/>
            </Router>
        </div>
    );
}

export default App;

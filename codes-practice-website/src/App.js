import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import Directories from "./data/Directories";
import {BrowserRouter} from "react-router-dom";

function App() {
  return (
    <div className="App">
        <BrowserRouter>

      <Navbar />
      <div className="container">
        <Directories/>
        </div>
      <Footer />
        </BrowserRouter>
    </div>
  );
}

export default App;

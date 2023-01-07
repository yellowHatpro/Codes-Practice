import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import Directories from "./data/Directories";

function App() {
  return (
    <div className="App">
      <Navbar />
      <div className="container">
        <Directories/>
        </div>
      <Footer />
    </div>
  );
}

export default App;

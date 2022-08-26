import "./App.css";
import Navbar from "./components/Navbar/Navbar";
import Footer from "./components/Footer/Footer";
import DisplayCard from "./components/Card/Card";

function App() {
  return (
    <div className="App">
      <Navbar />
      <DisplayCard />
      <Footer />
    </div>
  );
}

export default App;

import React from "react";
import "./Navbar.css";

const Navbar = ({path, handleBackPress}) => {

  return <div className="navbar">
    {path.length!==0 && <div className="back-press" onClick={()=>handleBackPress()}> ⬅️ </div>}
      Codes Practice
  </div>;
};

export default Navbar;

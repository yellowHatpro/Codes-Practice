import React from "react";
import "./Navbar.css";

const Navbar = ({setUrl, path, setPath}) => {
  console.log("Path: ", path)
  function constructUrl(newPath){
    const res = newPath.join('/')
    return res
  }

  const handlePath = () => {
     setPath((oldPath)=>{
      const newPath = [...oldPath]
      newPath.pop()
      return newPath
    })
  }

  const handleUrl = () => {
    const newPath = [...path]
    newPath.pop()
    const newStr = constructUrl(newPath)
    console.log(newPath)
    setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + newStr + "?ref=master")
  }

  const handleBackPress = () => {
    handlePath()
    handleUrl()
  }
   
  return <div className="navbar">
    {path.length!=0 && <div className="back-press" onClick={()=>handleBackPress()}> ⬅️ </div>}
      Codes Practice
  </div>;
};

export default Navbar;

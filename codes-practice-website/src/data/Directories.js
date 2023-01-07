import React, { useState, useEffect } from 'react';
import axios from "axios";
import DisplayCard from "../components/Card/Card";
import "./Directories.css";

function Directories() {

  const url = "https://api.github.com/repos/yellowhatpro/codes-practice/contents"
  const [product, setProduct] = useState(null)
  const headers = {
    'Authorization' : process.env.REACT_APP_GITHUB_TOKEN,
    'Accept' : 'application/vnd.github.v3+json'
  }
  useEffect(() => {

    axios.get(url,{} ,{headers: headers})
        .then(response => {
          setProduct(response.data)
        })
        }, [url])
  if (product){
    
  return (
      <div className='code-directories'>
       {product.map((productItem) => (
        <DisplayCard name={productItem.name} key={productItem.name}/>
       ))}
      </div>
  )
  }
  else {
    return (
        <div></div>
    )
  }
}
export default Directories;

import React, { useState, useEffect } from 'react';
import axios from "axios";
import DisplayCard from "../../components/Card/Card";
import "./Directories.css";
import {useNavigate, useParams} from "react-router-dom";


function Directories() {
    let {name} = useParams();
    const url = "https://api.github.com/repos/yellowhatpro/codes-practice/contents"
  const [product, setProduct] = useState(null)
  const headers = {
    'Authorization' : process.env.REACT_APP_GITHUB_TOKEN,
    'Accept' : 'application/vnd.github.v3+json'
  }

  const navigate = useNavigate()
  const goToDirectory = () =>{
      navigate("/"+name)
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
        <DisplayCard  name={productItem.name} onClick={() => {
            name = productItem.name
            goToDirectory()

        }} />
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
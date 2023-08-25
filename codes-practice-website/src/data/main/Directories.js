import React, { useState, useEffect } from 'react';
import axios from "axios";
import DisplayCard from "../../components/Card/Card";
import "./Directories.css";
import {useNavigate} from "react-router-dom";

const headers = {
        'Authorization': process.env.REACT_APP_GITHUB_TOKEN,
        'Accept': 'application/vnd.github.v3+json'
  }

function Directories({url, setUrl, path, setPath}) {
    const [product, setProduct] = useState([])
    const navigate = useNavigate()
    useEffect(() => {
        axios.get(url, {}, {headers: headers})
            .then(response => {
                const valv =  response.data.filter((item) => item.name[0] !== '.')
                setProduct(valv)
            })
    }, [url])

    

    const handleSetPath = (newPath) => {
    setPath(curr => [...curr, newPath])
    }

    function constructUrl(productItemName){
      const res = path.join('/')
      return `${res}/${productItemName}`
  }

    const handleCardClick = (productItemName) => {
      console.log(productItemName)
      handleSetPath(productItemName)
      const newStr = constructUrl(productItemName)
      const newName = `${newStr}/`
      console.log(`new name : ${newName}`)
      setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + newName + "?ref=master")
      navigate(newName)
    }
    
    if (product) {
        return (
            <div className='code-directories'>
                {product.map((productItem, i) => (
                    <DisplayCard key={i} name={productItem.name} onClick={ () => handleCardClick(productItem.name)  }/>
                ))}
            </div>
        )
    } else {
        return (
            <div> Loading ... </div>
        )
    }
}
export default Directories;

import React, { useState, useEffect } from 'react';
import axios from "axios";
import DisplayCard from "../../components/Card/Card";
import File from "../files/File"
import "./Directories.css";

const authHeaders = {
        'Authorization': `Bearer ${process.env.REACT_APP_GITHUB_TOKEN}`,
        'Accept': 'application/vnd.github.v3+json'
  }

function Directories({url, setUrl, path, setPath}) {
    const [product, setProduct] = useState([])
    useEffect(() => {
        axios.get(url, {}, {headers: authHeaders})
            .then(response => {
                setProduct(response.data)
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
      handleSetPath(productItemName)
      const newStr = constructUrl(productItemName)
      const newName = `${newStr}/`
      setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + newName + "?ref=master")
      
    }
    
    if (product.type==='file'){
      return <>
      <File url={product.download_url}/>
    </>
  } else {
        return (<>
            <h2>{`${product.length} Files and Folders`}</h2>
            <div className='code-directories'>
                {product.map((productItem, i) => (
                    <DisplayCard 
                      key={i}
                      name={productItem.name}
                      type={productItem.type}
                      onClick={ () => handleCardClick(productItem.name)   }/>
                ))}
            </div>
        </>)
    }  
}
export default Directories;

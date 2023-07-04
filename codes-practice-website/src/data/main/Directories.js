import React, { useState, useEffect } from 'react';
import axios from "axios";
import "./Directories.css";
import {Route, Routes} from "react-router-dom";
import Folder from './Folder.js';

function Directories() {

    const [name, setName] = useState("");
    const [url, setUrl] = useState("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents?ref=master")
    
    console.log("url: " + url)
    const [product, setProduct] = useState(null)
    const headers = {
        'Authorization': process.env.REACT_APP_GITHUB_TOKEN,
        'Accept': 'application/vnd.github.v3+json'
    }
    useEffect(() => {
        axios
            .get(url, {}, {headers: headers})
            .then((response) => {
                setProduct(response.data)
            },
              (error) => {
                console.log(error);
              })
    }, [url])

    if (product) {
        return (
            <div>
              <Routes>
              <Route 
                  path={"/*"} 
                  element={
              <Folder product={product} name = {name} setName = {setName} url = {url} setUrl = {setUrl}/>
          }>
            </Route>
            <Route path = {name+'/*'} element = {<Directories/>}>
            </Route>  
            </Routes>
            </div>
        )
    } else {
        return (
            <div className='code-directories'>No content</div>
        )
    }
}
export default Directories;

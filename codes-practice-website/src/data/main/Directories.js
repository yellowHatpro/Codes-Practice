import React, { useState, useEffect } from 'react';
import axios from "axios";
import DisplayCard from "../../components/Card/Card";
import "./Directories.css";
import {useNavigate, useParams} from "react-router-dom";


function Directories() {
    let {name = ""} = useParams();
    let [url, setUrl] = useState("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + name + "?ref=master");
    console.log("url: " + url)
    const [product, setProduct] = useState(null)
    const headers = {
        'Authorization': process.env.REACT_APP_GITHUB_TOKEN,
        'Accept': 'application/vnd.github.v3+json'
    }

    const navigate = useNavigate()

    useEffect(() => {

        axios.get(url, {}, {headers: headers})
            .then(response => {
                setProduct(response.data)
            })
    }, [url])
    if (product) {
        return (
            <div className='code-directories'>
                {product.map((productItem) => (
                    <DisplayCard name={productItem.name} onClick={() => {
                        name += "/" + productItem.name
                        setUrl("https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" + name + "?ref=master")
                        navigate(name)
                    }}/>
                ))}
            </div>
        )
    } else {
        return (
            <div></div>
        )
    }
}
export default Directories;

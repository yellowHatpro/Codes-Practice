import React, {useEffect, useState} from "react";
import "./InnerDirectory.css"
import {useNavigate, useParams} from "react-router-dom";
import axios from "axios";
import DisplayCard from "../../components/Card/Card";

function InnerDirectoryContent(){
    let {name} = useParams();
    const url = "https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/"+name+"?ref=master"
    const [product, setProduct] = useState(null)
    const headers = {
        'Authorization' : process.env.REACT_APP_GITHUB_TOKEN,
        'Accept' : 'application/vnd.github.v3+json'
    }

    const navigate = useNavigate()
    const goToDirectory = () =>{
        console.log("dd "+ name)
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
            <div className='inner-dir'>
                {product.map((productItem) => (
                    <DisplayCard  name={productItem.name} onClick={() => {
                        name +="/"+ productItem.name
                        console.log(name)
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

export default  InnerDirectoryContent


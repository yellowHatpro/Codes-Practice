import React, { useState, useEffect } from "react";
import DisplayCard from "../../components/Card/Card.jsx";
import File from "../files/File";
import "./Directories.css";
import { authHeaders } from "../../network/index.js";
import axios from "axios";
import { NETWORK_ERROR_CODE } from "../../constants.js";

function Directories({ url, setUrl, path, setPath }) {
  const [product, setProduct] = useState([]);
  const [error, setError] = useState("");

  useEffect(() => {
    try {
      axios
        .get(url, { headers: authHeaders })
        .then((response) => {
          setProduct(response.data);
        })
        .catch((err) => {
          setError(err.code);
        });
    } catch (e) {
      setError(e.toString());
      console.log("why");
    }
  }, [url]);

  const handleSetPath = (newPath) => {
    setPath((curr) => [...curr, newPath]);
  };

  function constructUrl(productItemName) {
    const res = path.join("/");
    return `${res}/${productItemName}`;
  }

  const handleCardClick = (productItemName) => {
    handleSetPath(productItemName);
    const newStr = constructUrl(productItemName);
    const newName = `${newStr}/`;
    setUrl(
      "https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/" +
      newName +
      "?ref=master",
    );
  };
  if (error === NETWORK_ERROR_CODE) {
    return <div className={"network-error"}>Please connect to internet</div>;
  }

  if (product.type === "file") {
    return (
      <>
        <File url={product?.download_url} />
      </>
    );
  } else {
    return (
      <>
        <h2>{`${product?.length} Files and Folders`}</h2>
        <div className="code-directories">
          {product.map((productItem, i) => (
            <DisplayCard
              key={i}
              name={productItem.name}
              type={productItem.type}
              onClick={() => handleCardClick(productItem.name)}
            />
          ))}
        </div>
      </>
    );
  }
}
export default Directories;

import React, { useState, useEffect } from "react";
import DisplayCard from "../../components/Card/Card.jsx";
import "./Directories.css";
import { fetchRepositoryData } from "../../network/index.js";
import {
  IGNORED_ENTRY_NAMES,
  IGNORED_FILE_EXTENSIONS,
  NETWORK_ERROR_CODE,
} from "../../constants.js";
import { Loading } from "../../components/Loading.jsx";

const shouldIgnoreEntry = (entry) => {
  if (IGNORED_ENTRY_NAMES.has(entry.name)) {
    return true;
  }

  return IGNORED_FILE_EXTENSIONS.some((extension) => entry.name.endsWith(extension));
};

function Directories({
  url,
  path,
  selectedFile,
  setDirectoryCount,
  handleNavigateDirectory,
  handleSelectFile,
}) {
  const [product, setProduct] = useState([]);
  const [error, setError] = useState("");
  const [isLoading, setIsLoading] = useState(true);

  useEffect(() => {
    let ignore = false;

    setIsLoading(true);
    setError("");

    fetchRepositoryData(url)
      .then((response) => {
        if (ignore) {
          return;
        }

        const nextItems = (Array.isArray(response) ? response : []).filter(
          (entry) => !shouldIgnoreEntry(entry),
        );
        nextItems.sort((left, right) => {
          if (left.type !== right.type) {
            return left.type === "dir" ? -1 : 1;
          }

          return left.name.localeCompare(right.name);
        });

        setProduct(nextItems);
        setDirectoryCount(nextItems.length);
      })
      .catch((err) => {
        if (!ignore) {
          setError(err.code || err.message);
          setDirectoryCount(0);
        }
      })
      .finally(() => {
        if (!ignore) {
          setIsLoading(false);
        }
      });

    return () => {
      ignore = true;
    };
  }, [url]);

  useEffect(() => {
    if (selectedFile && !product.some((item) => item.path === selectedFile.path)) {
      handleSelectFile(null, { recordHistory: false });
    }
  }, [product, selectedFile, handleSelectFile]);

  const handleCardClick = (productItem) => {
    if (productItem.type === "dir") {
      handleNavigateDirectory([...path, productItem.name]);
      return;
    }

    handleSelectFile(productItem);
  };

  if (error === NETWORK_ERROR_CODE) {
    return (
      <section className="workspace-panel explorer-panel network-error" aria-live="polite">
        <div>
          <span className="panel-kicker">Explorer</span>
          <h3>Connection required</h3>
          <p>Please connect to the internet to load repository contents.</p>
        </div>
      </section>
    );
  }

  if (isLoading) {
    return (
      <section className="workspace-panel explorer-panel">
        <div className="panel-heading">
          <div>
            <span className="panel-kicker">Explorer</span>
            <h3>Loading directory</h3>
          </div>
        </div>
        <Loading />
      </section>
    );
  }

  return (
    <section className="workspace-panel explorer-panel">
      <div className="panel-heading">
        <div>
          <span className="panel-kicker">Explorer</span>
          <h3>{path.length === 0 ? "~" : path[path.length - 1]}</h3>
        </div>
        <div className="panel-count">{product.length} entries</div>
      </div>

      <div className="code-directories" role="list">
        {product.map((productItem) => (
          <DisplayCard
            key={productItem.sha}
            name={productItem.name}
            type={productItem.type}
            isActive={selectedFile?.path === productItem.path}
            onClick={() => handleCardClick(productItem)}
          />
        ))}
      </div>
    </section>
  );
}

export default Directories;

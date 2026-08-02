import "./App.css";
import Navbar from "./components/Navbar/Navbar.jsx";
import Footer from "./components/Footer/Footer.jsx";
import Directories from "./pages/dir/Directories.jsx";
import { useEffect, useState } from "react";
import File from "./pages/files/File.jsx";
import { gh_url, buildContentsUrl } from "./utils.js";
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";

function App() {
  const [path, setPath] = useState([]);
  const [url, setUrl] = useState(gh_url);
  const [selectedFile, setSelectedFile] = useState(null);
  const [directoryCount, setDirectoryCount] = useState(0);
  const [past, setPast] = useState([]);
  const [future, setFuture] = useState([]);
  const [queryClient] = useState(() => new QueryClient());

  const currentSnapshot = {
    path,
    url,
    selectedFile,
  };

  const restoreSnapshot = (snapshot) => {
    setPath(snapshot.path);
    setUrl(snapshot.url);
    setSelectedFile(snapshot.selectedFile);
  };

  const pushSnapshot = () => {
    setPast((currentPast) => [...currentPast, currentSnapshot]);
    setFuture([]);
  };

  const handleNavigateDirectory = (nextPath, { recordHistory = true } = {}) => {
    if (recordHistory) {
      pushSnapshot();
    }

    setPath(nextPath);
    setUrl(buildContentsUrl(nextPath));
    setSelectedFile(null);
  };

  const handleSelectFile = (file, { recordHistory = true } = {}) => {
    if (recordHistory) {
      pushSnapshot();
    }

    setSelectedFile(file);
  };

  const handleBackPress = () => {
    if (past.length === 0) {
      return;
    }

    const previousSnapshot = past[past.length - 1];
    setPast((currentPast) => currentPast.slice(0, -1));
    setFuture((currentFuture) => [currentSnapshot, ...currentFuture]);
    restoreSnapshot(previousSnapshot);
  };

  const handleForwardPress = () => {
    if (future.length === 0) {
      return;
    }

    const [nextSnapshot, ...remainingFuture] = future;
    setFuture(remainingFuture);
    setPast((currentPast) => [...currentPast, currentSnapshot]);
    restoreSnapshot(nextSnapshot);
  };

  useEffect(() => {
    const handleMouseNavigation = (event) => {
      if (event.button === 3 && past.length > 0) {
        event.preventDefault();
        handleBackPress();
      }

      if (event.button === 4 && future.length > 0) {
        event.preventDefault();
        handleForwardPress();
      }
    };

    window.addEventListener("mouseup", handleMouseNavigation);

    return () => {
      window.removeEventListener("mouseup", handleMouseNavigation);
    };
  }, [past, future, currentSnapshot]);

  const currentPath = path.length === 0 ? "~" : path.join(" / ");
  const selectedLabel = selectedFile ? selectedFile.name : "No file selected";

  return (
    <QueryClientProvider client={queryClient}>
      <div className="app-shell">
        <Navbar
          path={path}
          currentPath={currentPath}
          selectedFile={selectedFile}
          handleBackPress={handleBackPress}
          canGoBack={past.length > 0}
        />

        <main className="app-main">
          <section className="app-section app-intro">
            <div className="section-grid intro-grid">
              <div className="intro-copy surface">
                <span className="announcement-pill">Repository index</span>
                <h1>yellowHatpro&apos;s coding journey lives here.</h1>
                <p>
                  A personal directory of algorithm problems I tackle with. Everything is organized to make the journey easy to browse and the code
                  easy to read.
                </p>
              </div>

              <div className="intro-stats">
                <article className="stat-block stat-block-dark surface">
                  <span className="stat-label">Current path</span>
                  <strong>{currentPath}</strong>
                </article>
                <article className="stat-block stat-block-blue surface">
                  <span className="stat-label">Visible entries</span>
                  <strong>{directoryCount}</strong>
                </article>
                <article className="stat-block surface">
                  <span className="stat-label">Selection</span>
                  <strong>{selectedLabel}</strong>
                </article>
              </div>
            </div>
          </section>

          <section className="app-section workspace-section">
            <div className="workspace-grid">
              <Directories
                url={url}
                path={path}
                selectedFile={selectedFile}
                setDirectoryCount={setDirectoryCount}
                handleNavigateDirectory={handleNavigateDirectory}
                handleSelectFile={handleSelectFile}
              />
              <File selectedFile={selectedFile} currentPath={currentPath} />
            </div>
          </section>
        </main>

        <Footer />
      </div>
    </QueryClientProvider>
  );
}

export default App;

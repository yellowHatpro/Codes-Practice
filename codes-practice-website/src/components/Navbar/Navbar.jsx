import React from "react";
import "./Navbar.css";

const Navbar = ({ currentPath, selectedFile, handleBackPress, canGoBack }) => {
  return (
    <header className="app-header">
      <div className="header-shell">
        <div className="header-brand-block">
          <span className="header-eyebrow">Codes Practice</span>
          <div className="header-title-row">
            <h2>Directory workspace</h2>
            {canGoBack && (
              <button className="back-press" type="button" onClick={handleBackPress}>
                Back
              </button>
            )}
          </div>
        </div>

        <nav className="header-path" aria-label="Current path">
          <span className="path-label">Path</span>
          <span className="path-value">{currentPath}</span>
        </nav>

        <div className="header-meta" aria-live="polite">
          <span className="meta-label">Active file</span>
          <span className="meta-value">{selectedFile ? selectedFile.name : "None"}</span>
        </div>
      </div>
    </header>
  );
};

export default Navbar;

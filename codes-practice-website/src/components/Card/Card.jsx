import React from "react";
import "./Card.css";

function DisplayCard({ onClick, name, type, isActive }) {
  const detail = type === "file" ? "source file" : "directory";

  return (
    <button
      className={`displayCard ${isActive ? "displayCard-active" : ""}`}
      type="button"
      onClick={onClick}
    >
      <span className="card-type">{type}</span>
      <span className="card-name">{name}</span>
      <span className="card-detail">{detail}</span>
    </button>
  );
}

export default DisplayCard;

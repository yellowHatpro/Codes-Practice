import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard({onClick, name, type}) {
    const icon = (type==='file') ? "📃" :"📂"
  return (
    <div className="displayCard" onClick={onClick}>
      <Card >
        <Card.Title>
          {
             `${icon} ${name}`
          }
        </Card.Title>
      </Card>
    </div>
  );
}

export default DisplayCard;

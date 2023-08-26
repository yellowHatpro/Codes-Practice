import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard({onClick, name}) {
  return (
    <div className="displayCard" onClick={onClick}>
      <Card >
        <Card.Title>{name}</Card.Title>
      </Card>
    </div>
  );
}

export default DisplayCard;

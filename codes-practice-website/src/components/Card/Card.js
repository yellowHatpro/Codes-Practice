import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard(type) {
  return (
    <div className="displayCard" onClick={type.onClick}>
      <Card >
        <Card.Title>{type.name}</Card.Title>
        <Card.Link href="#">{type.name}</Card.Link>
      </Card>
    </div>
  );
}

export default DisplayCard;

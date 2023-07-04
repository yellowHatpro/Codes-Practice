import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard(prop) {
  return (
    <div className="displayCard" onClick={prop.onClick}>
      <Card >
        <Card.Title>{prop.name}</Card.Title>
        <Card.Link href="#">{prop.name}</Card.Link>
      </Card>
    </div>
  );
}

export default DisplayCard;

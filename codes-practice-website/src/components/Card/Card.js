import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard({onClick, name}) {
  return (
    <div className="displayCard" onClick={onClick}>
      <Card >
        <Card.Title>{name}</Card.Title>
        <Card.Link href="#">{name}</Card.Link>
      </Card>
    </div>
  );
}

export default DisplayCard;

import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard(type) {
  return (
    <>
      <Card className="displayCard">
        <Card.Title>{type.name}</Card.Title>
        <Card.Subtitle>{type.name}</Card.Subtitle>
        <Card.Link href="#">{type.name}</Card.Link>
      </Card>
    </>
  );
}

export default DisplayCard;

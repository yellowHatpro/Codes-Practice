import React from "react";
import Card from "react-bootstrap/Card";
import "./Card.css";

function DisplayCard(type) {
  return (
    <>
      <Card className="displayCard">
        <Card.Title>Topic</Card.Title>
        <Card.Subtitle>Some description</Card.Subtitle>
        <Card.Link href="#">Show Problems done</Card.Link>
      </Card>
    </>
  );
}

export default DisplayCard;

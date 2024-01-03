SELECT w1.id
FROM Weather w1 
WHERE w1.temperature > (
  SELECT w2.temperature
  FROM Weather w2
  WHERE (w1.recordDate - w2.recordDate) = 1
)

SELECT e.name, b.bonus
FROM Employee e 
LEFT JOIN Bonus b 
ON e.empId = b.empId
WHERE b.bonus IS NULL or b.bonus < 1000

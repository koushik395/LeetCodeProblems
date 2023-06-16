# Write your MySQL query statement below
SELECT DISTINCT e2.email from Person as e1 
INNER JOIN Person as e2
ON e1.id !=  e2.id AND (e1.email = e2.email)
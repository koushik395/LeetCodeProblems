SELECT q1.person_name
FROM Queue as q1 JOIN Queue as q2
ON q1.turn >= q2.turn 
GROUP BY q1.turn
HAVING sum(q2.weight) <= 1000 
ORDER BY SUM(q2.weight) desc limit 1

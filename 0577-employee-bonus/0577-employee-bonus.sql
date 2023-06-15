# Write your MySQL query statement below
SELECT name,bonus from Employee as e LEFT JOIN Bonus as b
on e.empId = b.empId where bonus < 1000 or b.empId is NULL;
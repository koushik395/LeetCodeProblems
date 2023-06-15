# Write your MySQL query statement below
SELECT name from Employee where id 
IN (SELECT managerId from Employee group by managerId having count(managerId) >= 5)
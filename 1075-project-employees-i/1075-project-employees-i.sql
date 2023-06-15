# Write your MySQL query statement below
SELECT p.project_id , ROUND(SUM(e.experience_years)/COUNT(p.employee_id),2) as average_years
FROM Project as p INNER JOIN Employee as e
ON p.employee_id = e.employee_id
group by p.project_id
# Write your MySQL query statement below
SELECT s.product_id,s.year as first_year ,quantity, price FROM Sales as s 
WHERE (product_id,s.year) 
IN (SELECT product_id,min(s.year) FROM Sales as s group by product_id)
# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date,"%Y-%m") as month,
country,
count(id) as trans_count,
count(if(state = 'approved',1,NULL)) as approved_count,
SUM(amount) as trans_total_amount,
SUM(if(state = 'approved',amount,0)) as approved_total_amount
FROM transactions
GROUP BY month,country
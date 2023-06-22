# Write your MySQL query statement below
SELECT ROUND(AVG(IF(d.order_date = d.customer_pref_delivery_date,1,0))*100,2) as
immediate_percentage FROM Delivery as d
where (customer_id, order_date) IN
(select customer_id, min(order_date)
from delivery
group by customer_id)
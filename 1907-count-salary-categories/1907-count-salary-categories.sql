SELECT "Low Salary" as category, 
SUM(case WHEN income < "20000" then 1 else 0 end) as accounts_count
FROM Accounts

UNION 

SELECT "Average Salary" as category, 
SUM(case WHEN income >= "20000" and income <= "50000" then 1 else 0 end) as accounts_count
FROM Accounts

UNION

SELECT "High Salary" as category, 
SUM(case WHEN income > "50000" then 1 else 0 end) as accounts_count
FROM Accounts
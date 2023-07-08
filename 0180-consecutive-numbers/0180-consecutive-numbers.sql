SELECT distinct num as ConsecutiveNums 
FROM Logs
Where (id+1,num) in (SELECT * from Logs) and (id + 2, num) in (SELECT * from logs)

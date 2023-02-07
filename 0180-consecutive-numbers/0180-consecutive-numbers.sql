# Write your MySQL query statement below
# select distinct num as ConsecutiveNums from Logs 
# where(id+1,num) in (select * from Logs) and (id+2,num) in (select * from Logs);

select distinct num as 'ConsecutiveNums' from logs
where (id+1,num) in (select * from logs) and 
(id+2,num) in (select * from logs);
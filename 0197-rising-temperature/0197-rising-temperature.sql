# Write your MySQL query statement below
# select a.id from Weather a,Weather b
# where datediff(a.recordDate,b.recordDate)=1 and a.temperature>b.temperature;

select a.id from weather a,weather b
where DATEDIFF(a.recordDate,b.recordDate)=1 
and a.temperature>b.temperature;
# Write your MySQL query statement below
select a.name from Customer a
where  a.referee_id is null or a.referee_id!=2 ;
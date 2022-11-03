# Write your MySQL query statement below
select distinct(a.email) from person a,person b
where a.id!=b.id and a.email=b.email;
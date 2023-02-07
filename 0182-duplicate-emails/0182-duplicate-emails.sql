# Write your MySQL query statement below
# select distinct(a.email) from person a,person b
# where a.id!=b.id and a.email=b.email;
# select email from person p1 where  (select count(email)
#                                   from
#                                   person group by email) ;
select distinct(p1.email) from
person p1
join
person p2
on p1.email=p2.email
where p1.id!=p2.id;

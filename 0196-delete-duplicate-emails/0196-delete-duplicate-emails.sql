# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
# delete a.* from Person a,Person b
# where a.id>b.id and a.email=b.email;

delete p1.* from person p1,person p2
where p1.email=p2.email
and p1.id>p2.id;
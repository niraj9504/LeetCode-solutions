# Write your MySQL query statement below
select name from salesperson where sales_id not in(select a.sales_id from orders a
inner join
company b on a.com_id=b.com_id 
and b.name='RED');
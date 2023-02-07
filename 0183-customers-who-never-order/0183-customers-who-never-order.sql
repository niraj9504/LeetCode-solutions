# select c.name as Customers from Customers c
# left join 
# Orders o on c.id=o.customerId
# where o.customerId is NULL;
select name as 'Customers' from customers 
where id not in(select customerId from orders);

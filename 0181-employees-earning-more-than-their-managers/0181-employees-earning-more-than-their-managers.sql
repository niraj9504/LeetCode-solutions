# Write your MySQL query statement below
# select e.name as Employee from Employee e
# inner join
# Employee b on e.managerId=b.id where e.salary>b.salary;
select e1.name as 'Employee' from
Employee e1 where e1.salary >(select
            salary from employee e2 where 
            e1.managerId=e2.id);
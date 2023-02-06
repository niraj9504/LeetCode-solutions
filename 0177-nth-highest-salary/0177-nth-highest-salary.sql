CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    # declare m int;
    # set m=n-1;
  RETURN (
      # select distinct salary from Employee
      # order by salary desc
      # limit 1 offset m
      
      select distinct(e1.salary) from Employee e1 where n-1=(
            select count(distinct e2.salary) from Employee e2 where 
            e1.salary<e2.salary
      )
  );
END
# Write your MySQL query statement below
/*
select IFNULL(
    Null, 
    (select distinct Salary from Employee 
     order by Salary desc limit 1 offset 1)
 )
as SecondHighestSalary*/
Select IFNULL((select distinct salary from (select salary,dense_rank() over(order by salary desc) as denserank from Employee) temp where temp.denserank=2),NULL) as secondhighestsalary;
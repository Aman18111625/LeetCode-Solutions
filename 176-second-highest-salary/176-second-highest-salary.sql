# Write your MySQL query statement below
/*
select IFNULL(
    Null, 
    (select distinct Salary from Employee 
     order by Salary desc limit 1 offset 1)
 )
as SecondHighestSalary*/
Select Max(sal) as SecondHighestSalary  from (select Salary as sal, Rank() OVER (order by salary desc) as Rnk from Employee) T where Rnk=2 ;
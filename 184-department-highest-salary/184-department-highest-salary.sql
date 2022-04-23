# Write your MySQL query statement below
select department.name as department, employee.name as employee, salary from employee join department on employee.departmentid = department.id
where (departmentid,salary) in 
(select departmentid, max(salary) as salary from employee group by departmentid);  
# Write your MySQL query statement below
select employee_id from
(select employee_id from employees
where employee_id NOT IN (select employee_id from salaries)
UNION
select employee_id from salaries
where employee_id NOT IN (select employee_id from employees)) temp
order by employee_id;
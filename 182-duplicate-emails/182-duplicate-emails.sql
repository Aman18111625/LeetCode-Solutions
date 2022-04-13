# Write your MySQL query statement below
select email from (select email,count(email) as cnt from person group by email) temp where temp.cnt>1;

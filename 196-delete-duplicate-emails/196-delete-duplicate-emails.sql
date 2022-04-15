# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
/*
DELETE p from Person p, Person q where p.Id>q.Id AND q.Email=p.Email;*/
DELETE t2 from Person t1 
INNER JOIN 
person t2 
where t1.id<t2.id and t1.email=t2.email;
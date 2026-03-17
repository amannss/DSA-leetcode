# Write your MySQL query statement below
select c.name as Customers from Customers  c
where c.id not in ( 
select a.id  from Customers  a 
inner join Orders  b on 
a.id = b.customerId ) ;
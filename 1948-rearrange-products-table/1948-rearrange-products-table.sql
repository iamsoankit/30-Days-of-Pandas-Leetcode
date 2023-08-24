# Write your MySQL query statement below
SELECT product_id, 'store1' as store, store1 as price
FROM Products p1
where p1.store1 is not null
UNION
SELECT product_id, 'store2', store2
FROM Products p2
where p2.store2 is not null
UNION 
SELECT product_id, 'store3', store3
FROM Products p3
where p3.store3 is not null
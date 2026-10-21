# Write your MySQL query statement below
SELECT a.customer_id, count(*) AS count_no_trans FROM Visits a WHERE NOT EXISTS (
    SELECT 1 FROM Transactions b WHERE a.visit_id = b.visit_id
) GROUP BY a.customer_id;
# Write your MySQL query statement below
SELECT a.id FROM Weather a WHERE EXISTS (SELECT 1 FROM Weather b
  WHERE DATEDIFF(a.recordDate,b.recordDate) = 1 AND a.temperature > b.temperature);
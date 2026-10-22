SELECT machine_id, ROUND(AVG(end_time - start_time),3) as processing_time FROM (
    SELECT machine_id, process_id,MAX(CASE WHEN activity_type = 'start' THEN timestamp END) as start_time,
    MAX(CASE WHEN activity_type = 'end' THEN timestamp END) as end_time FROM Activity GROUP BY machine_id, process_id
) as t GROUP BY machine_id;
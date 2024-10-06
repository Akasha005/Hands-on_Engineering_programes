-- 6.1 Create tables N_RollCall and O_RollCall
CREATE TABLE N_RollCall (
    E_id INT,
    E_name VARCHAR(50),
    Age INT,
    Salary DECIMAL(10, 2)
);

CREATE TABLE O_RollCall (
    E_id INT,
    E_name VARCHAR(50),
    Age INT,
    Salary DECIMAL(10, 2)
);

-- 6.2 PL/SQL block using parameterized cursor to merge data
DECLARE
    CURSOR rollcall_cursor IS
        SELECT * FROM N_RollCall;
    rollcall_record rollcall_cursor%ROWTYPE;
BEGIN
    OPEN rollcall_cursor;
    LOOP
        FETCH rollcall_cursor INTO rollcall_record;
        EXIT WHEN rollcall_cursor%NOTFOUND;
        
        -- Merge data: if the data already exists in O_RollCall, skip it
        MERGE INTO O_RollCall o
        USING (SELECT rollcall_record.E_id, rollcall_record.E_name, rollcall_record.Age, rollcall_record.Salary FROM dual) n
        ON (o.E_id = n.E_id)
        WHEN NOT MATCHED THEN
            INSERT (E_id, E_name, Age, Salary) 
            VALUES (rollcall_record.E_id, rollcall_record.E_name, rollcall_record.Age, rollcall_record.Salary);
    END LOOP;
    CLOSE rollcall_cursor;
END;

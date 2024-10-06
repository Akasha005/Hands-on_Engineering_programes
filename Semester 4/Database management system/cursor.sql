-- 5.1 Create a cursor for the Employee table and extract values
DECLARE
    CURSOR employee_cursor IS
        SELECT E_id, E_name, Age, Salary FROM Employee_agg;
    employee_record employee_cursor%ROWTYPE;
BEGIN
    OPEN employee_cursor;
    LOOP
        FETCH employee_cursor INTO employee_record;
        EXIT WHEN employee_cursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Employee ID: ' || employee_record.E_id || ', Name: ' || employee_record.E_name || ', Age: ' || employee_record.Age || ', Salary: ' || employee_record.Salary);
    END LOOP;
    CLOSE employee_cursor;
END;

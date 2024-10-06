-- 4.1 Create the CUSTOMERS table
CREATE TABLE CUSTOMERS (
    ID INT,
    NAME VARCHAR(50),
    AGE INT,
    ADDRESS VARCHAR(100),
    SALARY DECIMAL(10, 2)
);

-- 4.2 Create a trigger to display salary difference between old and new salary
CREATE OR REPLACE TRIGGER salary_difference_trigger
BEFORE INSERT OR UPDATE OR DELETE ON CUSTOMERS
FOR EACH ROW
DECLARE
    old_salary CUSTOMERS.SALARY%TYPE;
    new_salary CUSTOMERS.SALARY%TYPE;
BEGIN
    IF :OLD.SALARY IS NOT NULL THEN
        old_salary := :OLD.SALARY;
    END IF;
    
    IF :NEW.SALARY IS NOT NULL THEN
        new_salary := :NEW.SALARY;
    END IF;
    
    DBMS_OUTPUT.PUT_LINE('Old Salary: ' || old_salary || ', New Salary: ' || new_salary);
END;

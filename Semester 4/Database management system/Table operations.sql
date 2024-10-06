-- 2.1 Create Employee table
CREATE TABLE Employee_new (
    EMPNO INT,
    ENAME VARCHAR(50),
    JOB VARCHAR(50),
    MGR INT,
    SAL DECIMAL(10, 2)
);

-- 2.2 Add column commission with domain to Employee table
ALTER TABLE Employee_new ADD COMMISSION DECIMAL(10, 2);

-- 2.3 Insert five records into the Employee table
INSERT INTO Employee_new VALUES (201, 'Alice', 'Manager', 2001, 65000, 2000);
INSERT INTO Employee_new VALUES (202, 'Bob', 'Clerk', 2002, 45000, 1500);
INSERT INTO Employee_new VALUES (203, 'Charlie', 'Salesman', 2003, 48000, 1300);
INSERT INTO Employee_new VALUES (204, 'David', 'Engineer', 2004, 72000, 2500);
INSERT INTO Employee_new VALUES (205, 'Eva', 'HR', 2005, 60000, 1000);

-- 2.4 Update the column details of job
UPDATE Employee_new SET JOB = 'Senior Clerk' WHERE EMPNO = 202;

-- 2.5 Rename the column of Employee table using ALTER command
ALTER TABLE Employee_new RENAME COLUMN ENAME TO EMPLOYEE_NAME;

-- 2.6 Delete the employee whose Empno is 105
DELETE FROM Employee_new WHERE EMPNO = 105;

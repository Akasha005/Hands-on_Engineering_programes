-- 1.1 Create a user and grant all permissions to theuser
CREATE USER theuser IDENTIFIED BY password;
GRANT ALL PRIVILEGES TO theuser;

-- 1.2 Create the Employee table
CREATE TABLE Employee (
    EMPNO INT,
    ENAME VARCHAR(50),
    JOB VARCHAR(50),
    MANAGER_NO INT,
    SAL DECIMAL(10, 2),
    COMMISSION DECIMAL(10, 2)
);

-- Insert three records into the employee table
INSERT INTO Employee VALUES (101, 'John', 'Manager', 1001, 55000, 1000);
INSERT INTO Employee VALUES (102, 'Jane', 'Clerk', 1002, 40000, 500);
INSERT INTO Employee VALUES (103, 'Doe', 'Salesman', 1003, 35000, 800);

-- Rollback after inserting records
ROLLBACK;

-- 1.3 Add primary key and NOT NULL constraints
ALTER TABLE Employee ADD CONSTRAINT pk_employee PRIMARY KEY (EMPNO);
ALTER TABLE Employee MODIFY (EMPNO NOT NULL, ENAME NOT NULL, JOB NOT NULL);

-- 1.4 Insert null values to the employee table and verify the result (this will fail)
INSERT INTO Employee VALUES (NULL, NULL, 'Manager', 1001, 55000, NULL);
-- The above query will fail due to the NOT NULL constraint.

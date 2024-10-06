-- 3.1 Create Employee table with attributes E_id, E_name, Age, Salary
CREATE TABLE Employee_agg (
    E_id INT,
    E_name VARCHAR(50),
    Age INT,
    Salary DECIMAL(10, 2)
);

-- Insert records into Employee_agg table
INSERT INTO Employee_agg VALUES (301, 'Frank', 35, 75000);
INSERT INTO Employee_agg VALUES (302, 'Grace', 28, 55000);
INSERT INTO Employee_agg VALUES (303, 'Henry', 42, 80000);
INSERT INTO Employee_agg VALUES (304, 'Ivy', 29, 62000);
INSERT INTO Employee_agg VALUES (305, 'Jack', 50, 90000);

-- 3.2 Count number of employee names from employee table
SELECT COUNT(E_name) FROM Employee_agg;

-- 3.3 Find the Maximum age from employee table
SELECT MAX(Age) FROM Employee_agg;

-- 3.4 Find the Minimum age from employee table
SELECT MIN(Age) FROM Employee_agg;

-- 3.5 Find salaries of employee in Ascending Order
SELECT Salary FROM Employee_agg ORDER BY Salary ASC;

-- 3.6 Find grouped salaries of employees
SELECT Salary, COUNT(*) FROM Employee_agg GROUP BY Salary;

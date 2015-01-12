# https://oj.leetcode.com/problems/nth-highest-salary/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
     SELECT DISTINCT(Emp1.Salary) FROM Employee Emp1 WHERE (N-1) =
     (SELECT COUNT(
        DISTINCT(Emp2.Salary))
        FROM Employee Emp2 WHERE Emp2.Salary > Emp1.Salary
     )
  );
END

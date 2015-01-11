# https://oj.leetcode.com/problems/combine-two-tables/

select FirstName, LastName, City, State from Person Left join Address on Person.PersonId = Address.PersonId;

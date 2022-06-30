-- List the titles of all movies in which both
-- Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
  FROM stars
 WHERE people.name = "Johnny Depp";
-- List the title and release years of all Harry Potter movies, in chronological order

SELECT movies.title, movies.year
  FROM movies
 WHERE movies.title LIKE "Harry Potter%"
 ORDER BY movies.year;
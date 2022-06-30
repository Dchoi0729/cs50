-- List the names of all people who starred in Toy Story

SELECT people.name
  FROM stars
  JOIN people ON people.id = stars.person_id
  JOIN movies ON movies.id = stars.movie_id
 WHERE movies.title = "Toy Story";
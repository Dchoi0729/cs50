-- List the titles of all movies in which both
-- Johnny Depp and Helena Bonham Carter starred

SELECT movies.title
  FROM stars
  JOIN movies ON movies.id = stars.movie_id
  JOIN people ON people.id = stars.person_id;

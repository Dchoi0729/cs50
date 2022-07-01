-- List the titles of the five highest rated movies (in order)
-- that Chadwick Boseman starred in, starting with highest rated

SELECT movies.title
  FROM stars
       JOIN movies ON movies.id = stars.movie_id
       JOIN people ON people.id = stars.person_id
       JOIN ratings on movies.id = ratings.movie_id
 WHERE people.name = "Chadwick Boseman"
 ORDER BY ratings.rating DESC
 LIMIT 5;
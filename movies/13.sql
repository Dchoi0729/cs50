-- List the names of all people who starred in a movie in which Kevin bacon also starred

SELECT people.name FROM people
 WHERE people.id IN stars.movie_id


person_id IN (people.id FROM people WHERE people.name = "Kevin Bacon" AND people.birth = 1958);
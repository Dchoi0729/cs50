-- List the names of all people who starred in a movie in which Kevin bacon also starred

SELECT people.name FROM
(SELECT person_id FROM
(SELECT stars.movie_id FROM people.id WHERE people.name = "Kevine Bacon" AND people.birth = 1958))
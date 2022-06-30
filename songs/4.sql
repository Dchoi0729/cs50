-- List the names of any songs that have danceability, energy and valence
-- greater than 0.75

SELECT songs.name
FROM songs WHERE
danceability > 0.75 OR
energy > 0.75 OR
valence > 0.75;
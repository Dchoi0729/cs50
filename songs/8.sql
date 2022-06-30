-- List the names of the songs that feature other artists

SELECT songs.name FROM songs
 WHERE songs.name LIKE "%feat%";
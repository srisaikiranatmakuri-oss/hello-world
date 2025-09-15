
-- 1st querie
SELECT name, runs FROM players ORDER BY runs DESC LIMIT 1;

-- 2nd querie
SELECT name, role, runs, wickets FROM players
WHERE role='Allrounder' AND (wickets > 40 OR runs > 2000)
ORDER BY runs DESC;

-- 3ed querie
SELECT AVG(batting_average) AS avg_batting_avg FROM players;

-- 4th querie
SELECT name, wickets FROM players
WHERE role='Bowler' AND wickets > 100
ORDER BY wickets DESC;

-- 5th querie
SELECT role, COUNT(*) AS count FROM players
GROUP BY role;

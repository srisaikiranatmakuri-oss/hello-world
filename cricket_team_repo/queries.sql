
-- 1) Top run-scorer
SELECT name, runs FROM players ORDER BY runs DESC LIMIT 1;

-- 2) Allrounders (role='Allrounder') with >40 wickets OR >2000 runs
SELECT name, role, runs, wickets FROM players
WHERE role='Allrounder' AND (wickets > 40 OR runs > 2000)
ORDER BY runs DESC;

-- 3) Team average batting average (exclude NULLs)
SELECT AVG(batting_average) AS avg_batting_avg FROM players;

-- 4) Bowlers with more than 100 wickets
SELECT name, wickets FROM players
WHERE role='Bowler' AND wickets > 100
ORDER BY wickets DESC;

-- 5) Count of players by role
SELECT role, COUNT(*) AS count FROM players
GROUP BY role;

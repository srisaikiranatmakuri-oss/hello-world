
-- 1) Top scorer
SELECT name, goals FROM football_players ORDER BY goals DESC LIMIT 1;

-- 2) Midfielders with more than 40 assists
SELECT name, assists FROM football_players WHERE position='Midfielder' AND assists > 40;

-- 3) Average goals scored by all players
SELECT AVG(goals) AS avg_goals FROM football_players;

-- 4) Players with more than 200 appearances
SELECT name, appearances FROM football_players WHERE appearances > 200;

-- 5) Count players by position
SELECT position, COUNT(*) as count FROM football_players GROUP BY position;

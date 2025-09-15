
-- SQL schema (works with SQLite / MySQL / Postgres with minimal edits)
CREATE TABLE players (
  player_id INTEGER PRIMARY KEY,
  name TEXT NOT NULL,
  jersey_no INTEGER,
  role TEXT,
  batting_style TEXT,
  bowling_style TEXT,
  dob DATE,
  nationality TEXT,
  is_captain BOOLEAN,
  is_keeper BOOLEAN,
  matches INTEGER,
  runs INTEGER,
  highest_score INTEGER,
  batting_average REAL,
  strike_rate REAL,
  hundreds INTEGER,
  fifties INTEGER,
  wickets INTEGER,
  best_bowling TEXT,
  bowling_average REAL,
  economy REAL,
  catches INTEGER,
  stumpings INTEGER
);

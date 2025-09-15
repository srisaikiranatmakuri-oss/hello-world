
# Cricket Team - sample MongoDB collection + SQL schema & queries

This repository contains:
- `data/mongo_team_players.json` — sample MongoDB documents for a cricket team
- `mongo_commands.js` — `mongosh` script to create `sportsDB.team_players` and insert the sample documents
- `schema.sql` — SQL schema (single flattened `players` table)
- `inserts.sql` — `INSERT` statements matching the sample dataset
- `queries.sql` — five example SQL queries appropriate for the table
- `results.md` — sample outputs for those queries (computed from the dataset)
- `README.md` — this file

## How to use

### 1) Load into MongoDB
Run (using `mongosh`):
```bash
mongosh mongo_commands.js
```
This creates `sportsDB` and a `team_players` collection with the sample documents.

### 2) Load into SQLite (quick test)
You can test the SQL queries quickly with SQLite:

```bash
# create a new sqlite database and load schema + inserts
sqlite3 team.db < schema.sql
sqlite3 team.db < inserts.sql

# run a sample query
sqlite3 team.db "SELECT name, runs FROM players ORDER BY runs DESC LIMIT 1;"
```

For MySQL / PostgreSQL you may need to adjust types (BOOLEAN, TEXT -> VARCHAR) and the `INSERT` syntax slightly.

### 3) Run the provided SQL queries
Open `queries.sql` for 5 example queries. `results.md` shows expected outputs computed from the sample dataset.

## How to publish to GitHub (step-by-step)

1. Create a new GitHub repository on github.com (click **New**).
2. On your local machine, initialize and push:

```bash
# in the directory where you want to create the repo locally:
git init
git add .
git commit -m "Add sample cricket team data + SQL schema and queries"
git branch -M main
# Replace <YOUR_GIT_REMOTE_URL> with the GitHub repo URL, e.g. git@github.com:you/cricket-team.git
git remote add origin <YOUR_GIT_REMOTE_URL>
git push -u origin main
```

That's it — your GitHub repo will contain the files.

## Five SQL queries (in `queries.sql`)
They are also explained in `results.md`.


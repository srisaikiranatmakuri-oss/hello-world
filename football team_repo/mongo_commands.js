
// MongoDB commands to create a football team collection
use sportsDB;

// Drop existing collection
db.football_players.drop();

// Insert players
db.football_players.insertMany([
  { name: "Leo Martinez", position: "Forward", goals: 120, assists: 60, appearances: 200, nationality: "Spain" },
  { name: "Ravi Desai", position: "Midfielder", goals: 45, assists: 95, appearances: 220, nationality: "India" },
  { name: "Marcus Green", position: "Defender", goals: 10, assists: 15, appearances: 250, nationality: "England" },
  { name: "Ahmed Khan", position: "Goalkeeper", goals: 0, assists: 2, appearances: 180, nationality: "Pakistan" },
  { name: "Lucas Silva", position: "Forward", goals: 85, assists: 40, appearances: 190, nationality: "Brazil" },
  { name: "Kenji Tanaka", position: "Midfielder", goals: 30, assists: 70, appearances: 210, nationality: "Japan" },
  { name: "Samuel Johnson", position: "Defender", goals: 8, assists: 20, appearances: 240, nationality: "USA" },
  { name: "Pierre Laurent", position: "Forward", goals: 95, assists: 55, appearances: 210, nationality: "France" },
  { name: "Diego Ramos", position: "Midfielder", goals: 50, assists: 85, appearances: 230, nationality: "Argentina" },
  { name: "Moussa Diallo", position: "Defender", goals: 6, assists: 12, appearances: 225, nationality: "Senegal" },
  { name: "Oliver Schmidt", position: "Goalkeeper", goals: 0, assists: 1, appearances: 175, nationality: "Germany" }
]);

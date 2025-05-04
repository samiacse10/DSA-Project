🚀 Overview:
In this project, you’ll simulate an autonomous drone fleet that:

Monitors crops

Detects threats (pests, dryness)

Navigates across plots efficiently

Logs inspection reports

Sorts field zones by priority (e.g., most affected)

🔧 Features & DSA Concepts Used:
Feature	DSA Concept
Field as a grid/graph	2D Array / Adjacency list
Coverage planning (exploration)	DFS
Threat detection and shortest alert delivery	BFS
Drone task log	Linked List
Prioritized field zones	Array Sorting

🧪 Sample Input:
Field layout with different zones (0=Healthy, 1=Drought, 2=Insect, 3=Obstacle)

Drone base location

Task: inspect all zones or alert nearest station

📤 Sample Output:
text
Copy
Edit
🚁 Drone #1 Coverage Path:
(0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)

🌾 Zone Threat Priority:
1. Zone (3,2) - Drought
2. Zone (1,3) - Insect
3. Zone (0,4) - Drought

📋 Task Log:
[Drone #1] Checked (1,2) - Healthy at 09:05 AM
[Drone #1] Checked (1,3) - Insect at 09:07 AM
💡 Why This is Unique:
Very few students build farming-focused DSA systems

Mimics real drone behavior over land plots

You can simulate environmental alerts, energy-efficient movement, and more

🧱 Key Data Structures:
int field[ROWS][COLS] → Grid of plots

DroneLog* head → Linked list for logs

Threat zones[] → Array of (x, y, type), sorted by severity

✅ Full Starter Code (C Implementation):
Let me now provide a simplified but complete working version in C that includes:

BFS (to alert base)

DFS (for inspection coverage)

Linked List (for logging)

Sorting (threat zones)

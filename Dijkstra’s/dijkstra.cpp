#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <stack>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adj;

public:
    void addEdge(const string &u, const string &v, int weight, bool directed = false) {
        adj[u].push_back({v, weight});
        if (!directed) {
            adj[v].push_back({u, weight});
        }
    }

    void dijkstra(const string &start, const string &end) {
        unordered_map<string, int> dist;
        unordered_map<string, string> parent;
        for (auto &node : adj) {
            dist[node.first] = numeric_limits<int>::max();
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[end] == numeric_limits<int>::max()) {
            cout << "No path exists from " << start << " to " << end << endl;
            return;
        }

        cout << "Shortest Path Cost: " << dist[end] << endl;

        stack<string> path;
        string current = end;
        while (current != start) {
            path.push(current);
            current = parent[current];
        }
        path.push(start);

        cout << "Path: ";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "C", 5);
    g.addEdge("B", "D", 10);
    g.addEdge("C", "E", 3);
    g.addEdge("E", "D", 4);
    g.addEdge("D", "F", 11);

    string start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    g.dijkstra(start, end);

    return 0;
}
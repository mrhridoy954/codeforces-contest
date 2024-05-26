#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {  // not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int solveTestCase(int n, int a, int b, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distFromA, distFromB;
    bfs(a, adj, distFromA);
    bfs(b, adj, distFromB);

    int maxSteps = 0;
    for (int i = 1; i <= n; ++i) {
        if (distFromA[i] <= distFromB[i]) {
            maxSteps = max(maxSteps, distFromB[i]);
        }
    }

    return maxSteps;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            edges[i] = {x, y};
        }

        cout << solveTestCase(n, a, b, edges) << endl;
    }

    return 0;
}

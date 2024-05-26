#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
int color[MAXN];
set<int> blackVertices;
int depth[MAXN], parent[MAXN][20];  // for LCA and depths
int n, q;

void addEdge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < 20; ++i) {
        if (parent[u][i-1] != -1) {
            parent[u][i] = parent[parent[u][i-1]][i-1];
        }
    }
    for (int v : tree[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

void preprocess() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 20; ++j) {
            parent[i][j] = -1;
        }
    }
    depth[1] = 0;
    dfs(1, -1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = 19; i >= 0; --i) {
        if (parent[u][i] != -1 && depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distance(int u, int v) {
    int lcaNode = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lcaNode];
}

bool checkChain() {
    if (blackVertices.empty()) return false;
    if (blackVertices.size() == 1) return true;

    int first = *blackVertices.begin();
    int farthest = first;
    for (int v : blackVertices) {
        if (distance(first, v) > distance(first, farthest)) {
            farthest = v;
        }
    }

    int secondFarthest = farthest;
    for (int v : blackVertices) {
        if (distance(farthest, v) > distance(farthest, secondFarthest)) {
            secondFarthest = v;
        }
    }

    int maxDist = distance(farthest, secondFarthest);
    return maxDist == (int)blackVertices.size() - 1;
}

void processTestCase() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
                 tree[i].clear();
    }
    blackVertices.clear();
  
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        if (color[i] == 1) {
            blackVertices.insert(i);
        }
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    preprocess();






    for (int i = 0; i < q; ++i) {
        int u;
             cin >> u;
        if (color[u] == 1) {
            color[u] = 0;
            blackVertices.erase(u);
        } else {
            color[u] = 1;
            blackVertices.insert(u);
        }

        if (checkChain()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        processTestCase();
    }
    return 0;
}

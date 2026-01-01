#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    static const int N = 1005;
    int adj[N][N];
    int n;
    bool vis[N];
    int key[N];

public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            key[i] = INT_MAX;
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int minKey() {
        int minVal = INT_MAX, minIndex = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && key[i] < minVal) {
                minVal = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int prim(int src) {
        key[src] = 0;
        int totalWeight = 0;

        for (int count = 1; count <= n; count++) {
            int u = minKey();
            if (u == -1) break;
            vis[u] = true;
            totalWeight += key[u];

            for (int v = 1; v <= n; v++) {
                if (adj[u][v] && !vis[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                }
            }
        }
        return totalWeight;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int mstWeight = g.prim(1);
    cout << mstWeight << "\n";

    return 0;
}

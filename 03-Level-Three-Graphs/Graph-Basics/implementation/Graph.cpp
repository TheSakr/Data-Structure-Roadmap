#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    static const int N = 1005;
    int adj[N][N];
    bool vis[N];
    int n;

public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void resetVisited() {
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
        }
    }

    void bfs(int start) {
        int q[N];
        int front = 0, back = 0;

        q[back++] = start;
        vis[start] = true;

        while (front < back) {
            int u = q[front++];

            for (int v = 1; v <= n; v++) {
                if (adj[u][v] && !vis[v]) {
                    vis[v] = true;
                    q[back++] = v;
                }
            }
        }
    }

    void dfs(int u) {
        vis[u] = true;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !vis[v]) {
                dfs(v);
            }
        }
    }
};

int main() {
    
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.bfs(1);
    g.resetVisited();
    g.dfs(1);

    return 0;
}

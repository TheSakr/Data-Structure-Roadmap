#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    static const int N = 1005;
    int adj[N][N];
    bool vis[N];
    int q[N];
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

    void bfs(int start) {
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.bfs(1);

    return 0;
}

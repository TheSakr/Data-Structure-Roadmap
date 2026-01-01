#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    static const int N = 1005;
    int adj[N][N];
    int n;
    int dist[N];
    bool vis[N];

public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 1; i <= n; i++) {
            dist[i] = INT_MAX;
            vis[i] = false;
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int minDistance() {
        int minVal = INT_MAX, minIndex = -1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dist[i] <= minVal) {
                minVal = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void dijkstra(int src) {
        dist[src] = 0;

        for (int count = 1; count <= n; count++) {
            int u = minDistance();
            if (u == -1) break;
            vis[u] = true;

            for (int v = 1; v <= n; v++) {
                if (!vis[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    void printDistances() {
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << "\n";
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

    g.dijkstra(1);
    g.printDistances();

    return 0;
}

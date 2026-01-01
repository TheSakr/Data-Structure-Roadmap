#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
};

class DisjointSet {
private:
    static const int N = 1005;
    int parent[N];
public:
    DisjointSet(int n) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }
};

class Graph {
private:
    int n, m;
    Edge edges[10005];
public:
    Graph(int nodes, int edgesCount) {
        n = nodes;
        m = edgesCount;
    }

    void addEdge(int idx, int u, int v, int w) {
        edges[idx] = Edge(u, v, w);
    }

    int kruskal() {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (edges[j].w > edges[j + 1].w) swap(edges[j], edges[j + 1]);
            }
        }

        DisjointSet ds(n);
        int totalWeight = 0;

        for (int i = 0; i < m; i++) {
            int uRoot = ds.find(edges[i].u);
            int vRoot = ds.find(edges[i].v);
            if (uRoot != vRoot) {
                totalWeight += edges[i].w;
                ds.unite(uRoot, vRoot);
            }
        }
        return totalWeight;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Graph g(n, m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(i, u, v, w);
    }

    int mstWeight = g.kruskal();
    cout << mstWeight << "\n";

    return 0;
}

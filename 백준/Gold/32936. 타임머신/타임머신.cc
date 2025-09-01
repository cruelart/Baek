#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int a, b;
    long long c;
    if (!(cin >> N >> M >> a >> b >> c)) return 0;

    vector<vector<int>> g(N + 1), gr(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    auto bfs_from = [&](int start, const vector<vector<int>>& G) {
        vector<int> dist(N + 1, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
        };

    // dist from 1 (forward)
    vector<int> dist1 = bfs_from(1, g);
    // dist to N (by BFS on reversed graph)
    vector<int> distN = bfs_from(N, gr);
    // dist from b (to check b -> a)
    vector<int> dist_b = bfs_from(b, g); // b -> ... forward

    // unreachable check (no path at all)
    if (dist1[N] == -1 && (dist1[a] == -1 || distN[b] == -1)) {
        // if N unreachable by any means (direct or via time machine impossible)
        cout << "x\n";
        return 0;
    }

    // check negative cycle possibility:
    // need: 1 -> a reachable, b -> a reachable (so cycle via time machine possible),
    // and cycle weight = (b->a length) - c < 0  AND from cycle we can reach N (i.e., distN[b] != -1)
    bool neg_inf = false;
    if (dist1[a] != -1 && dist_b[a] != -1 && distN[b] != -1) {
        if ((long long)dist_b[a] < c) neg_inf = true;
    }
    if (neg_inf) {
        cout << "-inf\n";
        return 0;
    }

    // otherwise evaluate finite options
    long long ans = INF;
    if (dist1[N] != -1) ans = min(ans, (long long)dist1[N]);
    if (dist1[a] != -1 && distN[b] != -1) {
        long long val = (long long)dist1[a] - c + (long long)distN[b];
        ans = min(ans, val);
    }

    if (ans == INF) cout << "x\n";
    else cout << ans << "\n";

    return 0;
}
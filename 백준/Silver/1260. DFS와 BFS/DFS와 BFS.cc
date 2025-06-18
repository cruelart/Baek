#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

map<int, vector<int>> graph;
set<int> visited_dfs;
set<int> visited_bfs;

void dfs(int node) {
    visited_dfs.insert(node);
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited_dfs.count(neighbor)) {
            dfs(neighbor);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited_bfs.insert(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited_bfs.count(neighbor)) {
                visited_bfs.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 무방향
    }

    // 정점 번호 작은 것부터 방문해야 하므로 정렬
    for (auto& p : graph) {
        int node = p.first;
        vector<int>& neighbors = p.second;
        sort(neighbors.begin(), neighbors.end());
    }

    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";

    return 0;
}
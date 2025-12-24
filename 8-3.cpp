#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
set<vector<int>> cycles;
int target;

void dfs(int u, int start) {
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]) {
        if (v == start && path.size() >= 2) {
            vector<int> cycle = path;
            cycle.push_back(start);
            auto it = find(cycle.begin(), cycle.end(), start);
            if (it != cycle.end()) {
                rotate(cycle.begin(), it, cycle.end());
                vector<int> min_cycle = cycle;
                for (int i = 1; i < cycle.size() - 1; ++i) {
                    rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
                    if (cycle < min_cycle) {
                        min_cycle = cycle;
                    }
                }
                vector<int> sorted_cycle(min_cycle.begin(), min_cycle.end() - 1);
                sort(sorted_cycle.begin(), sorted_cycle.end());
                cycles.insert(sorted_cycle);
            }
        }
        else if (!visited[v] && v != start) {
            dfs(v, start);
        }
    }
    visited[u] = false;
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> target;
    for (int neighbor : adj[target]) {
        visited.assign(n + 1, false);
        path.clear();
        visited[target] = true;
        dfs(neighbor, target);
    }
    if (cycles.empty()) {
        cout << -1 << endl;
    }
    else {
        for (const auto& cycle : cycles) {
            for (size_t i = 0; i < cycle.size(); ++i) {
                cout << cycle[i];
                if (i != cycle.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
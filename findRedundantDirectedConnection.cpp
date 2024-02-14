#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = sz(edges);
        vector<int> adj[n+1];
        for (const auto& edge : edges) {
            int u1 = edge[0], v1 = edge[1];
            adj[u1].push_back(v1);

            stack<int> s;
            vector<int> vis (n+1);
            bool cycle = false;
            for (int i = 1; i <= n; ++i) {
                if (vis[i]) continue;
                s.push(i);
                while (!s.empty() && !cycle) {
                    int u = s.top();
                    s.pop();
                    if (vis[u]) { continue; }

                    vis[u] = true;
                    for (int v : adj[u]) {
                        if (!vis[v]) s.push(v);
                        else {
                            cycle = true;
                            break;
                        }
                    }
                }
                if (cycle) return {u1, v1};
            }
        }
        return {};
    }
};

void test() {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> ans = {2, 3};
//    for (auto& el : Solution().findRedundantDirectedConnection(edges))
//        cout << el << ' ';
//    cout << '\n';
    assert(Solution().findRedundantDirectedConnection(edges) == ans);

    edges = {{1,2},{2,3},{3, 4}, {4, 1}, {1, 5}};
    ans = {4, 1};
    assert(Solution().findRedundantDirectedConnection(edges) == ans);
}

int main() {
    test();
    return 0;
}

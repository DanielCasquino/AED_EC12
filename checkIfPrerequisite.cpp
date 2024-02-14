#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool g[numCourses][numCourses];
        memset(g,0,numCourses*numCourses*sizeof(bool));
        for (const auto& vec : prerequisites) {
            int u = vec[0], v = vec[1];
            g[u][v] = true;
        }

        stack<int> s;
        set<int> stk;
        vector<bool> vis (numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i]) continue;
            s.push(i);
            while (!s.empty()) {
                int u = s.top();
                if (vis[u]) { s.pop(); stk.erase(u); continue; }

                vis[u] = true;
                stk.insert(u);
                for (const auto& v : stk) g[v][u] = true;
                for (int v = 0; v < numCourses; ++v)
                    if (g[u][v] && !vis[v]) s.push(v);
            }
        }

        int m = sz(queries);
        vector<bool> ans (m);
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = g[u][v];
        }

        return ans;
    }
};

void test() {
    vector<vector<int>> pre = {{1, 0}};
    vector<vector<int>> q = {{0, 1}, {1, 0}};
    vector<bool> ans = {false, true};
    assert(Solution().checkIfPrerequisite(2, pre, q) == ans);

    pre = {{1, 2}, {1, 0}, {2, 0}};
    q = {{1, 0}, {1, 2}};
    ans = {true, true};
    assert(Solution().checkIfPrerequisite(2, pre, q) == ans);
}

int main() {
    test();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int> &root, int i){
        return root[i] == i ? i : find(root, root[i]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        vector<int> root(n+1, 0);
        for(auto &e: edges){
            if(parent[e[1]] == 0){
                parent[e[1]] = e[0];
            }else{
                candA = {parent[e[1]], e[1]};
                candB = e;
                e[1] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            root[i] = i;
        }
        for(auto &e: edges){
            if(e[1] == 0) continue;
            int u = e[0], v = e[1], pu = find(root, u);
            if(pu == v){
                if(candA.empty()) return e;
                return candA;
            }
            root[v] = pu;
        }
        return candB;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {4,1},{1,5}};
    vector<int> res = s.findRedundantDirectedConnection(edges);
    for(auto &i: res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
};

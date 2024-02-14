#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
    bool isBipartite(int i, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &colored)
    {
        // LOGIC:
        // Start dfs, check for neighbours. If they haven't been painted, paint them opposite color of current node.
        // Else check if they have the same color. If they do, return false :)

        stack<int> traversalStack;
        traversalStack.push(i);
        visited[i] = true;

        while (!traversalStack.empty()) // DFS
        {
            int curr = traversalStack.top();
            traversalStack.pop();

            for (auto neighbour : graph[curr])
            {
                if (!visited[neighbour]) // If they havent been visited, paint them the opposite color and mark them as visited. Add to stack as well
                {
                    traversalStack.push(neighbour);
                    visited[neighbour] = true;
                    colored[neighbour] = !colored[curr];
                }
                else // Node already visited (and therefore painted)
                {
                    if (colored[neighbour] == colored[curr]) // Check for same color
                    {
                        return false; // Not bipartite
                    }
                }
            }
        }
        return true; // Is bipartite
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<bool> visited(v, false);
        vector<bool> colored(v, false);
        for (int i = 0; i < v; ++i)
            if (!isBipartite(i, graph, visited, colored))
                return false;
        return true;
    }
};

// int main()
// {
//     vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
//     vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
//     cout << boolalpha << Solution().isBipartite(graph1) << endl
//          << Solution().isBipartite(graph2);
//     return 0;
// }

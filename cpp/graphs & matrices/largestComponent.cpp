// return the size of the largest connected component in the graph

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

int largestComponent(std::unordered_map<int, std::vector<int>> graph)
{
    int maxCompSize = 0;
    std::unordered_set<int> visited;

    for (auto node : graph)
    {
        if (visited.find(node.first) == visited.end())
        {
            int currCompSize = 1;

            // bfs
            std::queue<int> q;
            q.push(node.first);

            while (q.size() > 0)
            {
                int curr = q.front();
                visited.insert(curr);
                q.pop();

                for (int n : graph[curr])
                {
                    if (visited.find(n) == visited.end())
                    {
                        q.push(n);
                        visited.insert(n);
                        currCompSize++;
                    }
                }
            }

            maxCompSize = std::max(maxCompSize, currCompSize);
        }
    }

    return maxCompSize;
}
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

// Approach: run bfs on every node that's not visited and each connnected node you visit,
// flag it as visited. then whatever node you find is not visited will be the start of
// a new connected component

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph)
{
    int result = 0;
    std::unordered_set<int> visited;

    for (auto node : graph)
    {
        if (visited.find(node.first) == visited.end())
        {
            // start of a new connected component
            result++;

            // breadth first search
            std::queue<int> q;
            q.push(node.first);

            while (q.size() > 0)
            {
                int curr = q.front();
                visited.insert(curr);
                q.pop();

                for (int n : graph[curr])
                {
                    // only adding again in queue that are not visited already
                    // to prevent cyclic loops
                    if (visited.find(n) == visited.end())
                    {
                        q.push(n);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    std::unordered_map<int, std::vector<int>> graph{
        {0, {8, 1, 5}},
        {1, {0}},
        {5, {0, 8}},
        {8, {0, 5}},
        {2, {3, 4}},
        {3, {2, 4}},
        {4, {3, 2}}};
    std::cout << connectedComponentsCount(graph) << std::endl;
}
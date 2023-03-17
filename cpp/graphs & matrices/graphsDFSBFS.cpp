// Depth first and Breadth first traversal of graph

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

void depthFirstSearch(unordered_map<string, vector<string>> graph, string start)
{
    cout << "dfs:" << endl;
    unordered_set<string> visited;
    stack<string> st;
    st.push(start);

    while (st.size() > 0)
    {
        string curr = st.top();
        cout << curr << endl;
        visited.insert(curr);
        st.pop();

        for (string neighbor : graph[curr])
        {
            if (visited.find(neighbor) == visited.end())
            {
                st.push(neighbor);
            }
        }
    }
}

void breadthFirstSearch(unordered_map<string, vector<string>> graph, string start)
{
    cout << "bfs:" << endl;
    unordered_set<string> visited;
    queue<string> q;
    q.push(start);

    while (q.size() > 0)
    {
        string curr = q.front();
        cout << curr << endl;
        q.pop();

        for (string neighbor : graph[curr])
        {
            if (visited.find(neighbor) == visited.end())
            {
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    unordered_map<string, vector<string>> graph = {
        {"a", {"b", "c"}},
        {"b", {"d"}},
        {"c", {}},
        {"d", {}}};

    depthFirstSearch(graph, "a");
    breadthFirstSearch(graph, "a");
}
// The function should return a boolean indicating whether
// or not there exists a directed path between the source and
// destination nodes.

#include <unordered_map>
#include <vector>
#include <string>
#include <stack>

bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst)
{
    std::stack<std::string> st;
    st.push(src);

    while (st.size() > 0)
    {
        std::string curr = st.top();
        if (curr == dst)
        {
            return true;
        }

        st.pop();

        for (std::string neighbor : graph[curr])
        {
            st.push(neighbor);
        }
    }

    return false;
}

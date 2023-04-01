// Leetcode 1046

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;

        // add all weights in the pq
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        // remove two greatest and add their abs diff to pq until one remains
        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x != y)
            {
                pq.push(y - x);
            }
        }

        return pq.size() ? pq.top() : 0;
    }
};
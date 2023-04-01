// Leetcode 49

// approach is to generate a hashmap that contains the info about char frequencies as a key
// and each string is added to the key which matches the character frequency

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;

        for (string s : strs)
        {
            string key = generateKey(s);
            m[key].push_back(s);
        }

        vector<vector<string>> r;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            r.push_back(it->second);
        }

        return r;
    }

private:
    string generateKey(string s)
    {
        int count[26] = {0};

        for (int c : s)
        {
            count[c - 'a']++;
        }

        string key = "";

        for (int i : count)
        {
            key.append(to_string(i) + '.');
        }

        return key;
    }
};
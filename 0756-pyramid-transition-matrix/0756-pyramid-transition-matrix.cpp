class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string bottom, unordered_map<string, vector<char>> &mp, int idx, string &temp)
    {
        // If bottom reduces to single block → valid pyramid
        if (bottom.length() == 1) return true;

        // Memoization: if already computed
        if (idx == 0 && memo.count(bottom)) 
            return memo[bottom];

        string sub = bottom.substr(idx, 2);

        if (mp.count(sub))
        {
            vector<char> &vec = mp[sub];
            for (int i = 0; i < vec.size(); i++)
            {
                char c = vec[i];
                temp.push_back(c);

                if (temp.size() == bottom.size() - 1)
                {
                    string empty = "";
                    if (solve(temp, mp, 0, empty))
                        return memo[bottom] = true;
                }
                else
                {
                    if (solve(bottom, mp, idx + 1, temp))
                        return memo[bottom] = true;
                }

                temp.pop_back();
            }
        }

        // Store result as false
        if (idx == 0) memo[bottom] = false;
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for (auto &s : allowed)
        {
            string sub = s.substr(0, 2);
            mp[sub].push_back(s[2]);
        }

        string temp = "";
        return solve(bottom, mp, 0, temp);
    }
};

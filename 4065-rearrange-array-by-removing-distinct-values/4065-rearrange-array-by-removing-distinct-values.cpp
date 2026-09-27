class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        map<int, int> mp;

        for(auto it : nums)
        {
            mp[it]++;
        }

        while(!mp.empty())
        {
            for(auto it : mp)
            {
                int k = it.first;
                result.push_back(k);
                mp[k]--;
            }

            for(auto it = mp.begin(); it != mp.end(); )
            {
                if(it->second == 0)
                    it = mp.erase(it);
                else
                    it++;
            }
        }

        return result;
    }
};
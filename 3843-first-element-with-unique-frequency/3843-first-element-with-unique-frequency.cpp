class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq ;
        unordered_map<int ,int> freqtimes ;
        for(auto it : nums) freq[it]++ ;
        for(auto it : freq)
        {
            int n = it.first ;
            int f =it.second ;
            freqtimes[f]++ ;
        }
        for(auto it : nums)
        {
            if(freqtimes[freq[it]] == 1) return it ;
        }
        return -1 ;
    }
};
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        vector<int> copy = happiness ;
        sort(copy.begin() , copy.end() , greater<int>()) ;
        sort(happiness.begin() , happiness.end() ,greater<int>()) ;
        vector<int> temp ;
        int i= 0;
        while(k--  )
        {
               temp.push_back(happiness[i]) ;
               i++ ;
        }
        long long ans = 0 ;
        for(int i = 0 ;i< temp.size() ;i++)
        {   
            int rem = (temp[i]-i) > 0 ? temp[i] - i : 0 ;
            ans += rem;
        }
        return ans ;
    }
};
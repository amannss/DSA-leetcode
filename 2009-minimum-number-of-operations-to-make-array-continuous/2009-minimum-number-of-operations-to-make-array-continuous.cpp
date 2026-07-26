class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size()  ;
        set<int > st(begin(nums) , end(nums)) ;
        vector<int>temp(begin(st) , end(st)) ;
        int ans = INT_MAX ;
        for(int i = 0;i < temp.size();i++)
        {
            int L = temp[i] ;
            int R = L + n -1 ;

            int j =  upper_bound(begin(temp) , end(temp) , R) - begin(temp); // gives index

            int withinrange = j -i ;
            int outofrange = n - withinrange ;
            ans = min (ans , outofrange) ;
        }
        return ans ;
    }
};
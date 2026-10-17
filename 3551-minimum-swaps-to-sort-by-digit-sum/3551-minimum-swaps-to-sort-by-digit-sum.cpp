class Solution {
public:
    int findsum(int x){
        int sum = 0 ;
        while(x >0 )
        {
            int r = x% 10 ;
            sum += r ;
            x= x/10 ;
        }
        return sum ;
    }
    
    int minSwaps(vector<int>& nums) {

        auto cmp = [this](int a , int b){
        int sa = findsum(a) ;
        int sb = findsum(b) ;
        if(sa != sb){
            return sa < sb ;
        }
        return a < b ;
        };

        int n = nums.size() ;
        vector<int> aftersorted(nums) ;

        unordered_map<int , int> mp ;
        for(int i = 0 ;i<n;i++) mp[nums[i]] = i ;
        sort(aftersorted.begin() , aftersorted.end() , cmp) ;

        int swaps = 0 ;
        for(int i = 0 ; i<n;i++)
        {   
            int expectedval= aftersorted[i] ;
            int currval = nums[i] ;
            
            if(expectedval != currval)
            {
                int idx = mp[expectedval] ;
                
                nums[i] = expectedval ;
                nums[idx] = currval; 

                mp[expectedval] = i ;
                mp[currval] = idx;
                swaps++ ;
            }
            
        }
        return swaps;

    }
};
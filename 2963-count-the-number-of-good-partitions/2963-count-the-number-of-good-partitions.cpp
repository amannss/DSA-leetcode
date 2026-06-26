class Solution {
public:
int mod = 1e9 + 7 ;

    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , int > mp ; 
        for(int i =0;i<n;i++)
        {
            int num = nums[i] ;
            mp[num] = i ;
        }
        int i = 0;
        int j = mp[nums[0]] ;
        int result =  1; 
        while(i<n)
        {   
            if(i>j)
            {
            result = 2* result %mod ;
            }
            j =max(j ,  mp[nums[i]] ) ;
            i++ ;
        }
        return result ; 
    }
};
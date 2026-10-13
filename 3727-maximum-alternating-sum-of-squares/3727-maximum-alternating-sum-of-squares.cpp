class Solution {
public:
// static bool cmp(int &a, int &b){
//     if(a<0) a = -1 * a ;
//     else if(b < 0 )  b = -1 * b ;
//     return a> b ;
// }
    long long maxAlternatingSum(vector<int>& nums) {

        // comparator
       auto cmp =[](int a, int b){
        return abs(a)> abs(b) ;
        };
        long long ans = 0 ;int n = nums.size() ;
        sort(nums.begin() , nums.end() , cmp) ;
        int i = 0 , j = n-1 ;
        while(i<=j){
            if(i==j){
                long long x = nums[i++] ;
                x*=x ;
                ans += x ;
                break ;
            }
            long long a = abs(nums[i++]) ;
            long long b = abs(nums[j--]) ;
            a*=a ;b*=b ;
            ans += a-b ;
        }
        return ans ;
    }
};
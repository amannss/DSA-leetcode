class Solution {
public:
typedef long long ll ; 

    int numTrees(int v) {
        // ncr = n! /r!(n-r)!
        // in catalan number 
        // n = 2n aand r = n where n is given so 
        // let ncr
        int n = 2*v ;
        int r= v ;
        
        ll ans = 1  ;
        for(int i =1 ; i<=r ;i++)
        {
            ans = ans *(n-r+i) ;
            ans = ans / i  ;
        }
        ans /= (v+1 ) ; // catalan formula 
        return ans ;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n==1) return true ;
        // if(n==0) return false ;
        // return isPowerOfThree(n/3);
        return n > 0 && 1162261467 % n == 0;
    }
};
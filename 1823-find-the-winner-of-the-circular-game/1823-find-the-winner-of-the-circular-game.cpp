class Solution {
public:
    int find(int n , int k)
    {
        if(n == 1 ) return 0 ;
        int  idx = find(n - 1 , k ) ;
        idx = (idx + k) % n ;
        return idx ;
    }
    int findTheWinner(int n, int k) {
        int result = find(n , k ) ;
        return result+1 ;
    }
};
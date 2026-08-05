class Solution {
public:
    int candy(vector<int>& ratings) {
        int n  = ratings.size() ;
        vector<int> l2r(n , 1 ) ;
        vector<int> r2l(n , 1 ) ;
        for(int i = 1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                l2r[i] = 1 + l2r[i-1] ;
            }
        }
        for(int j = n -2 ;j >= 0 ;j--)
        {
            if(ratings[j] > ratings[j+1]) 
            {
                r2l[j] = 1 + r2l[j+1] ;
            }
        }
        int s = 0;
        for(int i = 0;i<n;i++)
        {
            int val = max(l2r[i] , r2l[i]) ;
            s+=val ;
        }
        return s ;
    }
};
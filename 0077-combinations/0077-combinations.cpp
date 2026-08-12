class Solution {
public:
vector<vector<int>>result ;
    void solve(int idx, int n , int k , vector<int>& vec)
    {
        if(vec.size() == k)
        {
            result.push_back(vec) ;
            return ;
        }   

        for(int i = idx; i<=n ; i++ )
        {   
                vec.push_back(i) ;
                solve(i+1 ,n , k ,vec) ;
                vec.pop_back() ;
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec ;
        solve( 1, n , k , vec) ;
        return result ;
    }
};
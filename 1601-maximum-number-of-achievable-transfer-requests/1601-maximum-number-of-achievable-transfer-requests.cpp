class Solution {
public:
int ans = 0 ;
bool res(vector<int> resultant)
{
    for(auto it : resultant) if(it !=0 ) return false ;
    return true ;
}
    void solve(int idx, int n , int cnt ,vector<int> resultant , vector<vector<int>>&requests)
    {
        if(idx == requests.size())
        {
            if(res(resultant) ) ans = max(cnt , ans ) ;
            return ;
        }
        int from = requests[idx][0] ;
        int to = requests[idx][1] ;
        resultant[from]-- ;
        resultant[to]++ ;
        solve(idx + 1 , n , cnt + 1, resultant, requests) ;
        resultant[from]++ ; 
        resultant[to]-- ;
        solve(idx + 1 , n , cnt , resultant , requests) ;
        return ;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> resultant(n , 0 ) ;
        solve(0 , n , 0 , resultant , requests) ;
        return  ans ;
    }
};
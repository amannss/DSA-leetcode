class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n = a.size() ;
        vector<vector<int>> result ;
        int i = 0 ;
        while(i < n && a[i][1] < b[0]  )
        {
            result.push_back(a[i]) ;
            i++ ;
        }
        while(i < n && a[i][0] <= b[1])
        {
            b[0] = min(b[0],a[i][0] ) ;
            b[1] = max(b[1],a[i][1] ) ;
            i++ ;
        }
        result.push_back(b) ;
        while(i < n)
        {
            result.push_back(a[i]) ;i++ ;
        }
        return result ;
    }
};
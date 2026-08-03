class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i = 0 , j = 0 ;
        int n1=  a.size() ; int n2 = b.size() ;
        vector<vector<int>> result ;
        while(i<n1 && j < n2 )
        {
            int s1 = a[i][0] ; int e1 = a[i][1] ;
            int s2 = b[j][0] ; int e2 = b[j][1] ;
            // checking if intersections 
            if( s2 <= e1 && s1 <= e2)
            {
                int u = max(s1 , s2  ) ;
                int v = min(e1 , e2 ) ;
                result.push_back({u,v}) ;
            }

            if(e1 < e2 ) i++ ;
            else if(e1 > e2 ) j++ ;
            else { i++ ; j++ ;}
        }
        return result ;
    }
};
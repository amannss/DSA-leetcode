class Solution {
public:
static bool cmp(vector<int>&a, vector<int>&b)
{
    return a[1] < b[1] ;
}
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size() ;
        int cnt = 0 ;
        int min ;
        int i = 0 ;
        sort(points.begin() ,points.end()  ,cmp) ;
        while(i < n )
        {
            min = points[i][1] ;
            int j = i +1 ;
            while(j < n && min >= points[j][0]) j++ ;
            cnt++ ;
            i = j ;
        }
        return cnt ;
    }
};
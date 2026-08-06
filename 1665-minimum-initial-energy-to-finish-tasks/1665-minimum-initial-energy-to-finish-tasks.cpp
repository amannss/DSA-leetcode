class Solution {
public:
static bool cmp(vector<int>&a, vector<int>&b)
{
    return (a[1] - a[0]) > (b[1] - b[0]) ;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size() ;
        sort(tasks.begin() , tasks.end() , cmp) ;
        int cnt = 0 ;int rem = 0 ;
        for(auto it : tasks)
        {   
            if(rem <= it[1]) 
            { 
                cnt += it[1] - rem ;
                rem = it[1] - it[0] ;
            }
            else rem = rem - it[0] ;
        }
        return cnt ;
    }
};
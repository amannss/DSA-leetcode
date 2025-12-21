class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n , 0) ;
        for(auto &it : roads)
        {
            int u = it[0] ;
            int v = it[1] ;
            indegree[u]++ ;
            indegree[v]++ ;
        }
        
        map<int, vector<int>> mp ;
        vector<int> ranks(n ,0) ;
        for(int i= 0;i<n;i++)
        {
            mp[indegree[i]].push_back(i) ;
        }
        int cnt  = 1; 
        for(auto  it : mp)
        {
            vector<int> vec = it . second ;
            for(int i = 0; i< vec.size() ;i++)
            {
                ranks[vec[i]] = cnt ;
                cnt++ ;
            }
        }
        long long ans = 0 ;
        for(int i =0 ; i< roads.size(); i++)
        {   
            int u = roads[i][0] ;int v = roads[i][1] ;
            ans += ranks[u] + ranks[v];
        }
        return ans ;
    }
};
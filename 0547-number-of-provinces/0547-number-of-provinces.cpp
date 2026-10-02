class Solution {
public:
    void dfs(unordered_map<int , vector<int>>&mp ,int u , vector<bool>& visited)
    {
        visited[u] = true ;
        for(auto v : mp[u])
        {
            if(!visited[v]) dfs(mp, v, visited) ;
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int , vector<int>> mp ; int n = isConnected.size() ;
        for(int i = 0 ; i < n;i++)
        {
            for(int  j = 0 ; j <n;j++ )
            {
                if(i == j ) continue ;
                if(isConnected[i][j] == 1)
                {
                    mp[i].push_back(j) ;
                    mp[j].push_back(i) ;
                }
            }
        }
        int ans= 0 ;
        vector<bool> visited(n ,false ) ;
        for(int i = 0 ; i < n;i++)
        {   
            
            if(!visited[i]){  dfs(mp, i , visited) ;ans++ ; }
        }
        return ans ;
    }
};
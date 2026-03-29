class Solution {
public:
    vector<vector<int>> result ;
    int time = 1;
    void dfs(int node , int parent , vector<int>&tin,vector<int>&low,vector<int>&visited, vector<int> adj[])
    {
        visited[node] = 1; 
        tin[node] = low[node] = time ;
        time++ ; // for neighbour
        for(auto v : adj[node])
        {
            if(v == parent) continue ;
            else if(visited[v] == 0 )
            {
                dfs(v, node ,tin , low, visited ,adj ); 
                // return from dfs 
                low[node] = min(low[node] , low[v]) ;
                // check for bridge 
                if(low[v] > tin[node])
                {
                    result.push_back({node ,v}) ;
                }
            }
            else // already visited
            {
                low[node] = min(low[node] , low[v]) ;
            }
        }
    }
   
        

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n,0) ;
        vector<int> low(n,0) ;
        vector<int> visited(n,0) ;
        vector<int> adj[n] ; // vector<vector<int>> 
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); 
        }
        dfs(0,-1,tin ,low ,visited ,adj) ;
        return result ;
    }
};
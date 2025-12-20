class Solution {
public:
int N ;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return{0} ;
        unordered_map<int , vector<int>> adj ;
        N = n ;
        for(auto &it : edges)
        {
            int u =it[0] ;
            int v =it[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        vector<int> indegree(n ,0 ) ;
        vector<int> result ;
        for(int i=0;i<edges.size() ; i++)
        {
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            indegree[u]++ ;
            indegree[v]++ ;
        }
        queue<int> q ;

        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 1) 
            {
                q.push(i) ;
            }
        }
        while(n>2)
        {
            int size = q.size() ;
            n-= size 
             ;
            while(size--)
            {
                int u = q.front() ; q.pop() ;
                for(int &v : adj[u])
                {
                    indegree[v]-- ;
                    if(indegree[v] == 1)
                    {
                        q.push(v) ;
                        
                    }
                }
            }
        }
        while(!q.empty())
        {
            int tops = q.front() ;q.pop(); 
            result.push_back(tops) ;
        }
        return result ;
    }
};
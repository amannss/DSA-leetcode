class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int , int > mp ; // child to parent 
        unordered_map<int ,vector<int>> adj ;
        //s1 only one parent check
        for(int i = 0 ;i<n;i++)
        {   
            int parent = i ;
            int l = leftChild[i] ;
            int r = rightChild[i] ;
            if(l!= -1 ) 
            {   
                adj[i].push_back(l) ;
                if(mp.find(l) != mp.end()) return false ;// pehle se parent hai
                mp[l] = i ;
            }
            if(r!= -1 )
            {       
                adj[i].push_back(r) ;
                if(mp.find(r) != mp.end()) return false ;
                mp[r] = i  ;
            }
        }
        //s2 only one component 
        // root will not present in mp cause its not child of any
        int root = -1 ;
        for(int i = 0 ; i < n;i++)
        {
            if(mp.find(i) == mp.end())
            {   
                if(root!=-1) return false ;// more than one root , so more than one component
                root= i ;
            }
        }
        if(root== -1 ) return false ;// root not found
        //s3 traversal
        int cnt =1 ;
        queue<int> q ;
        q.push(root) ;
        vector<bool> visited(n , false ) ;
        visited[root] = true ;
        while(!q.empty())
        {
            int node = q.front() ; q.pop() ;
            for(auto& v : adj[node])
            {
                if(!visited[v])
                {
                    visited[v] = true ;
                    q.push(v) ;
                    cnt++ ;
                }
            }
        }
        
        return cnt == n; 
    }
};
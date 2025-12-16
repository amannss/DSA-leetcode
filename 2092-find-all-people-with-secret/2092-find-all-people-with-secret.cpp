class Solution {
public:
typedef pair<int,int> p ;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int , vector<p>> timemeetings ;
        
        for(auto &it : meetings)
        {
            int p1 = it[0] ;
            int p2 = it[1] ;
            int t = it[2] ;
            timemeetings[t].push_back({p1,p2}) ;
        }
        // alreaty knows 
        vector<bool> knows(n , false ) ;
        knows[0] = true ;
        knows[firstPerson] = true ;
        for(auto &it : timemeetings)
        {
            int t = it.first ;
            vector<p> meets = it.second ;

            unordered_map<int, vector<int>> adj ;
            unordered_set<int> alreadyadded ;
            queue<int> q ;
            for(auto &[p1 , p2] : meets)
            {
                adj[p1].push_back(p2) ;
                adj[p2].push_back(p1) ;

                if(knows[p1]== true && alreadyadded.find(p1)==alreadyadded.end())
                {
                    q.push(p1); alreadyadded.insert(p1) ;
                }
                if(knows[p2]== true && alreadyadded.find(p2)==alreadyadded.end())
                {
                    q.push(p2); alreadyadded.insert(p2) ;
                }
            }
            while(!q.empty())
            {
                    int p = q.front() ; q.pop() ;
                    for(auto &next : adj[p])
                    {
                        if(knows[next]==false )
                        {
                            knows[next] = true ;
                            q.push(next) ;
                        }
                    }
            }
        }
        vector<int> result ;
        for(int i=0;i<n;i++)
        {
            if(knows[i]== true) result.push_back(i) ;
        }
        return result; 
    }
};
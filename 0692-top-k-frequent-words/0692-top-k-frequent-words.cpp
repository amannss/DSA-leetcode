class Solution {
public:
typedef pair<int , string > p ;
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp  = [] (p a, p b)
        {
            if(a.first == b.first) // frequency equal
            {
                return a.second < b.second ;
            }
            else return a.first > b.first ;
        };
        priority_queue<p , vector<p> ,  decltype(cmp) > pq ;
        unordered_map<string , int > mp ;
        for(auto it : words ) mp[it]++ ;
        for(auto it : mp)
        {
            string s = it.first ;
            int val = it.second ;
            pq.push({val , s }) ;
            if(pq.size()> k) pq.pop() ;
        }
        vector<string > result ;
        while (!pq.empty()) 
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin() , result.end()) ;
        return result ;
    }
};
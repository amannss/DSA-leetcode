class Solution {
public:
typedef pair <int , char > p ;
    string reorganizeString(string s) {
        vector<int > count(26 , 0 ) ;int n = s.length() ;
        for(auto c : s )
        {
            count[c - 'a']++ ; 
            if(count[c - 'a'] > ( n +1 )/ 2) return "" ;
        }
        priority_queue< p , vector<p>> pq ;
        for(int i = 0 ; i < 26 ; i++)
        {
            char c = i + 'a' ;
            if(count[i] > 0 )
            {
                pq.push({count[i] , c}) ;
            }
        }
        string result = ""; 
        while(pq.size() >=2 )
        {
            auto a= pq.top() ; pq.pop() ;
            auto b= pq.top() ; pq.pop() ;
            result.push_back(a.second ) ; a.first-- ;
            result.push_back(b.second ) ; b.first-- ;
            if(a.first > 0) pq.push(a) ;
            if(b.first > 0) pq.push(b) ;

        } 
        if(!pq.empty()) result.push_back(pq.top().second);
        return result ;
    }
};
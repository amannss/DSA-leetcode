class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int m = s.length() ; int n = goal.length() ;
        if(m!= n) return false ;
        if(s== goal)
        {
            for(int i =0;i<m;i++)
            {   // we have to swap 1 pair even if strings are same 
                // so find similar one like aa , bb
                if(count(s.begin() , s.end() , s[i]) > 1) return true ;
            }
            return false ;
        }
        vector<int > index ;
        for(int i= 0 ;i< m;i++)
        {
            if(s[i] != goal[i]) index.push_back(i) ;
        }
        if(index.size() != 2 ) return false ;
        swap(s[index[0]] , s[index[1]]) ;
        return s== goal ;
    }
};
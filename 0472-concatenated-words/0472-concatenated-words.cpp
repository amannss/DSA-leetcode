class Solution {
public:
    unordered_set<string> st ; 
    unordered_map<string , bool > mp ;
    bool isconcatenated(string s , vector<string> &result)
    {
        int n= s.length(); 
        if(mp.find(s) != mp.end()) return mp[s] ;
        for(int i = 0  ;i < n;i++)
        {
            string pre= s.substr(0 , i +1 ) ;
            string suf =s.substr(i + 1 );
            if( ( st.find(pre )!= st.end() && isconcatenated(suf , result) ) ||
                ( st.find(pre )!= st.end() && st.find(suf)!=st.end() )
            ) return mp[s]=true ; 
        }
        return mp[s] = false ;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=  words.size() ;
        mp.clear() ;
        for(auto it : words) st.insert(it) ;
        vector<string> result ;
        for(int i=0;i<n;i++)
        {
            if(isconcatenated(words[i] , result) )
            {
                result.push_back(words[i]) ;
            } 
        }
        return result ;
    }
};
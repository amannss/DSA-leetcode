class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st ;
        unordered_set<string> result ;
        vector<string> ans ;
        int n = s.length() ;
        string temp = "" ;
        int j = 0 ;
        int i = 0 ;
        while(j< 10 )
        {
            temp+=s[j++] ;
        }
        st.insert(temp) ;
        while(j<n)
        {
            temp.erase(0,1) ;
            i++; 
            temp+=s[j] ;
            if(st.find(temp) != st.end()){ 
                if(result.find(temp) == result.end())
                {
                    result.insert(temp) ;
                    ans.push_back(temp) ;
                }
            }
            st.insert(temp) ;
            j++ ;
        }
        return ans ;
    }
};
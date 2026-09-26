class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp ;
        for(auto it : knowledge)
        {
            string key = it[0] ;
            string value = it[1] ;
            mp[key] = value ;
        }
        int i = 0 ; string ans = "" ;
        int n = s.length() ;
        while(i<n)
        {
            if(s[i] != '(')
            {
                ans+=s[i] ;
            }
            else
            {   
                i++ ;
                string temp = "" ;
                while(s[i] != ')')
                {
                    temp += s[i] ;
                    i++ ;
                }
                if(mp.find(temp) != mp.end() )
                {
                    string val = mp[temp] ;
                    ans+=val ;
                }
                else ans +='?' ;
            }
            i++ ;
        }
        return ans; 
    }
};
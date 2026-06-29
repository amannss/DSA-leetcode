class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length() ;
        int ans = 0 ;
        for(int i=0;i<n;i++)
        {   
            unordered_map<char , int > mp ;
            for(int j =i ;j<n;j++)
            {
                mp[s[j]]++ ;
                int freq = mp[s[j]] ;
                if(j - i + 1 > ans )
                {   
                    bool check = true ;
                    for(auto it : mp)
                    {
                        if(it.second != freq  )  { check = false ; break ; }
                    }
                    if(check){ // means all freq same 
                        ans = max(ans, j-i +1 ) ;
                    }
                }
            }
        }
        return ans ;
    }
};
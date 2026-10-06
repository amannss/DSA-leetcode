class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length() ;
        stack<char> st ;

        int cnt = 0 ;
        int ans = 0 ;
        for(int i =0  ;i<n;i++)
        {
            if(s[i] == '('){
                cnt++ ;
            }
            else{
                if(cnt >0) cnt-- ;
                else{
                    ans++ ;
                }
            }
        }
        ans+= cnt ;
        return ans ;
    }
};
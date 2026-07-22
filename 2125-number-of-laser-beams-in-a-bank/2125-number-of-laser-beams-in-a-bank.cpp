class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        stack<int> st ;
        int cnt = 0 ;
        int n = bank.size() ;
        for(int i =0 ;i < n;i++)
        {
            int m = bank[i].length() ;
            cnt = 0 ;
            for(int j =0;j<m;j++)
            {
                if(bank[i][j] == '1') cnt++ ;
            }
            if(cnt != 0 ) st.push(cnt) ;
        }
        int ans = 0 ;
        while(!st.empty())
        {
            int x = st.top() ; st.pop() ;
            int y = 0 ;
            if(!st.empty())
            {
                 y = st.top() ; 
            ans +=  ( x*y )  ;
            }
        }
        return ans ;
    }
};
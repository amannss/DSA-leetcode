class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st ;
        for(auto &it : deadends) st.insert(it) ;
        if(st.find("0000")!= st.end()) return -1 
        ;
        queue<string> q ;
        int level =0 ;
        q.push("0000") ;
        while(!q.empty())
        {   
            int size = q.size() ;
            while(size--)
            {   
                string s = q.front() ;
                if(s == target ) return level ;
                q.pop() ;
                for(int i=0;i<4 ;i++)
                {   
                    string temp = s ;

                    char ch = s[i] ;
                    char inc =( ch == '9' ?'0':ch + 1 ) ;
                    temp[i] = inc ;
                    if(st.find(temp) == st.end())// not in deadend
                    {
                        st.insert(temp) ;
                        q.push(temp) ;
                    }
                    temp = s; 
                    char dec = (ch =='0' ? '9' : ch - 1 );
                    temp[i] = dec ;
                    if(st.find(temp) ==st.end())
                    {
                        st.insert(temp) ;
                        q.push(temp) ;
                    }
                }
            }
            level++ ;
        }
    return -1 ;
    }
    
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> index(26 ) ;
        vector<bool> taken(26, false ) ;
        for(int i = 0; i<s.length() ;i++)
        {   
            char ch = s[i] ;
            index[ch - 'a'] = i  ;
        }
        for(int i = 0;i<s.length() ;i++)
        {   
            char c = s[i] ;
            if(taken[c-'a'] ==false)
            {
                while( !st.empty() && st.top() > c && index[st.top()-'a'] > i)
                {   
                    // removed from stack so mark it not taken 
                    taken[st.top() - 'a']=false ;
                    st.pop() ;
                }
                st.push(c) ;
                taken[c-'a'] = true ;
            }
        }
        string k="" ;
        while(!st.empty())
        {   
            char c = st.top() ;
            st.pop() ;
            k+= c; 
        }
        reverse(k.begin()  , k.end() );
        return k ;
    }
};
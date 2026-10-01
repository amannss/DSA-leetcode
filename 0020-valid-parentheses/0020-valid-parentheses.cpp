class Solution {
public:
    bool isValid(string s) {
        stack<char> stacks ;
        for(int i =0 ; i < s.length() ; i++)
        {
            if(s[i]=='('|| s[i]=='{' || s[i]=='[') stacks.push(s[i]) ;
            else 
            {
                if(stacks.empty()) return false ;
                char ch = stacks.top() ;stacks.pop() ;
            if((s[i]==')' && ch=='(' )|| (s[i]=='}' && ch=='{') ||( s[i]==']' && ch=='[') )
                    continue;
            else return false ;
            }
        }
        return stacks.empty() ;
    }
};
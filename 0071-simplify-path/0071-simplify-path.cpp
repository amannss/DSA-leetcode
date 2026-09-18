class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        stringstream ss(path);
        string temp;
        
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue;
            }
            
            if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }
        
        if (st.empty()) {
            return "/";
        }
        
        string ans = "";
        
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
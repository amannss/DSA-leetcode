class Solution {
public:
    unordered_set<string> st;
    int maxlen = 0;
    vector<string> result;

    void solve(string &s, int n, int i, int open, int close,
               string &temp, int currlen) {

        if(close > open) return;

        if(i >= n) {
            if(open == close) {

                if(currlen > maxlen) {
                    maxlen = currlen;
                    st.clear();
                }

                if(currlen == maxlen) {
                    st.insert(temp);
                }
            }
            return;
        }

        char c = s[i];

        if(isalpha(c)) {

            temp.push_back(c);

            solve(s, n, i + 1, open, close,
                  temp, currlen + 1);

            temp.pop_back();
        }

        else if(c == '(') {

            // take
            temp.push_back('(');

            solve(s, n, i + 1, open + 1, close,
                  temp, currlen + 1);

            temp.pop_back();

            // not take
            solve(s, n, i + 1, open, close,
                  temp, currlen);
        }

        else {

            // take
            if(open > close) {

                temp.push_back(')');

                solve(s, n, i + 1, open, close + 1,
                      temp, currlen + 1);

                temp.pop_back();
            }

            // not take
            solve(s, n, i + 1, open, close,
                  temp, currlen);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();
        result.clear();
        maxlen = 0;

        int n = s.length();

        string temp = "";

        solve(s, n, 0, 0, 0, temp, 0);

        for(auto it : st) {
            result.push_back(it);
        }

        return result;
    }
};
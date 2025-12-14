class Solution {
public:
    string reverseWords(string s) {
        int cnt = 0;
        int n = s.length();
        int i = 0;

        // count vowels in first word
        while (i < n && s[i] != ' ') {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                cnt++;
            i++;
        }

        string ans = s.substr(0, i);

        if (i < n)
            s = s.substr(i + 1);
        else
            return ans;

        stringstream ss(s);
        string word;

        while (ss >> word) {
            int cntc = 0;

            for (int j = 0; j < word.length(); j++) {
                if (word[j]=='a'||word[j]=='e'||word[j]=='i'||word[j]=='o'||word[j]=='u')
                    cntc++;
            }

            if (cntc == cnt)
                reverse(word.begin(), word.end());

            ans += " " + word;
        }

        return ans;
    }
};

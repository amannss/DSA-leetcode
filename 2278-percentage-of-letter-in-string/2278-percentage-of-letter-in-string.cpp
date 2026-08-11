class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0 ;
        int n= s.length() ;
        for(int i = 0;i<n;i++) if(s[i] == letter) cnt++ ;
        return (cnt*100)  / n   ;
    }
};
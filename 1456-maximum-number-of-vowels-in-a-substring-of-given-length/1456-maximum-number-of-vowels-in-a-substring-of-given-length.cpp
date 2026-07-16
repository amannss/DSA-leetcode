class Solution {
public:
bool isvowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ) return true ;
    return false ;

}
    int maxVowels(string s, int k) {
        int n  = s.length() ;
        int i=0,j=0 ;
        int ans = 0 ; int cnt =0;
        while(j < k)
        {
            if(isvowel(s[j++]) )
            {
                cnt++ ;
            }
        }
        ans = cnt ;
        while( j < n)
        {
            if(isvowel(s[i])) cnt-- ;
            i++ ;
            if(isvowel(s[j])) cnt++ ;
            j++ ;
            ans = max(ans , cnt ) ;
        }
        return ans ;
    }
};
class Solution {
public:
bool isvowel(char c)
{
    if(c == 'a' || c =='i' || c=='e' || c=='o' || c== 'u')
    {
        return true ;
    }
    return false ;
}
    int beautifulSubstrings(string s, int k) {
        int n= s.length() ;
        int ans =0 ;
        for(int i =0 ; i < n ;i++)
        {   
            int vcnt =0, ccnt =0 ;
            for(int j=i ; j < n;j++) 
            {
                if(isvowel(s[j])) vcnt++ ;
                else ccnt++ ;
            if(ccnt == vcnt && (vcnt * ccnt ) % k == 0) ans++ ;
            }
        }
        return ans ;
    }
};
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1 =s1.length() ;
        int n2 =s2.length() ;
        int i = 0 ,j =0 ,k =0 ;
        if(n1 != n2) return false ;
        while(i < n2)
        {
            if(s1[k] == s2[i]){i++ ;k++ ; continue ;}
            int j = k+2 ;
            while(j<n1)
            {
                if(s1[j] == s2[i] && (j-k)%2 == 0)
                {
                    swap(s1[k] , s1[j]) ;
                    i++; k++ ;
                    break ;
                }
                j+=2 ;
            }
            if(j>=n1) return false ;
        }
        return true ;
    }
};
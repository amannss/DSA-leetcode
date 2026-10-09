class Solution {
public:
    int minInsertions(string s) {
        int n  = s.length() ;
        int opencnt = 0 ;
        int currcnt = 0 ;
        int i = 0 ; 
        string temp= "" ;
        while(i < n)
        {
            if(s[i] == '(')
            {
                if(currcnt != 0)
                {
                    temp.push_back(')') ;
                    currcnt++ ;
                }
                temp.push_back('(') ;
                opencnt++ ;
            }
            else if(opencnt==0)
            {
                temp.push_back('(') ;
                temp.push_back(')') ;
                opencnt++ ;
                currcnt++ ;
            }
            else
            {
                currcnt++ ;
                temp.push_back(')');
            }
            if(currcnt == 2){
                opencnt-- ;
                currcnt = 0;
            }
            i++ ;
        }
        if(currcnt == 1 )  { temp.push_back(')');opencnt-- ;}
        while(opencnt > 0)
        {
            temp.push_back(')');
            temp.push_back(')');
            opencnt-- ;
        }
        return  temp.length() - s.length();
    }
};
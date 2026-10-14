class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "" ;
        while(sum > 0 && num >0)
        {   
            string temp = to_string(sum) ;
            if(temp.size() > num ) return "" ;
            
            if(sum >= 9)
            {
                ans.push_back('9') ;
                sum -= 9 ; 
            }
            else 
            {   
                ans+=temp ;
                sum= 0 ;
            }
            num--;
        }
        while(num > 0){
            num-- ;
            ans+="0" ;
        }
        return ans ;
    }
};
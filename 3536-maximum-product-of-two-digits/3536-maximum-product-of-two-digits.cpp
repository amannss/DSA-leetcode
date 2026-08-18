class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec; 
        int r ;
        while(n>0)
        {
            r = n%10 ;
            n=n/10 ;
            vec.push_back(r) ;
        }
        sort(vec.begin(),vec.end() , greater<int>()) ;
        return vec[0]*vec[1] ;
    }
};
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin() , apple.end() , 0 ) ;
        vector<int> copy = capacity ;
        sort(copy.begin() ,  copy.end() ,greater<int>()) ;
        int cnt = 0 ;
        int n = copy.size() ;int i ;
        for(i= 0 ;i < n;i++)
        {
            cnt += copy[i] ;
            if(cnt >= sum) break ;
        }
        return i+1 ;
    }
};
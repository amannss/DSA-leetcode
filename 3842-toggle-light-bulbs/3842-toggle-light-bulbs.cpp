class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> vec(101, 0) ;
        for(auto it : bulbs)
        {
            if(vec[it] == 0) vec[it] = 1 ;
            else vec[it] = 0 ;
        }
        vector<int> result ;
        for(int i =1;i<101;i++)
        {
            if(vec[i] == 1) result.push_back(i) ;
        }
        sort(result.begin() , result.end() ) ;
        return result ;
    }
};
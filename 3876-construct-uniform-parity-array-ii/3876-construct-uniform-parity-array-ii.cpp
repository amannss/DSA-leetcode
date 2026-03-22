class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size() ;
        sort(nums1.begin() , nums1.end() , greater<int>()) ;
        int cnteven =0, cntodd = 0 ;
        vector<pair<int ,int>> vec(n ,{0,0}) ;
        for(int j =n-1 ; j>=0 ;j--)
        {
            
            if(nums1[j] % 2 == 0 ) 
            {  
                if(cntodd >= 1 ) vec[j].second  =1 ;
                cnteven++ ;vec[j].first = 1 ;
            }
            else 
            {
                if(cntodd >= 1 ) vec[j].first = 1 ;
                
                cntodd++ ;  vec[j].second = 1 ; 
            }
        }
        if(cnteven == n || cntodd == n ) return true ;
        for(int i = 0  ; i < n-1;i++)
        {
            auto p1 = vec[i] ;
            auto p2 = vec[i+1] ;
            if(p1.first == p2.first || p1.second == p2.second ) continue ;
            else return false ;
        }
        return true; 

    }
};
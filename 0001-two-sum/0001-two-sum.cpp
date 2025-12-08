class Solution {
public:
     vector<int> twoSum(vector<int>& a, int s) {
    int n = a.size();
  
    map<int , int> mp;
    int rem= 0;
    for(int i = 0 ; i < n ; i++)
    {   rem = s - a[i] ; 
        if(mp.find(rem) != mp.end())
        {
            return {i , mp[rem] }; 
        }
        mp[a[i]] = i ;
    
    }
    return {-1,-1} ;
    }
};
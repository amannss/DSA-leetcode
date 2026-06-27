class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length() ;
        unordered_map<char, int > mp  ;
        for(int i =0;i<n;i++) 
        {
            mp[s[i]] = i ;
        } 
        int i = 0 ;int j = mp[s[0]] ;
        vector<int> result ;
        int k = 0 ;
        while(i <= n) 
        {
            if(i > j ) // new partition formed add last one value 
            {   

                result.push_back(j-k+1) ;
                k=j+1 ; 
            }
            j = max(j , mp[s[i]]) ;
            i++ ;
        }
        return result ;
    }
};
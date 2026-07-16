class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int > mp ;
        for(char c : s1) 
        {
            mp[c]-- ;
        }
        int n1= s1.length() , n2 = s2.length() ;
        int i = 0 ; int j = 0 ;
        if(n1 > n2) return false ;
        while(j<n1)
        {   
            char ch = s2[j++] ;
            mp[ch]++ ;
            if(mp[ch]==0) mp.erase(ch) ;
        }
        if(mp.size() == 0) return true ;
        while(j<n2)
        {
            mp[s2[i]]-- ;
            if(mp[s2[i]] == 0 ) mp.erase(s2[i]) ;
            i++ ;
            mp[s2[j]]++ ;
            if(mp[s2[j]] == 0) mp.erase(s2[j]) ;
            j++ ;
            if(mp.size() ==0 ) return true  ;
        }
        return false ;
    }
};
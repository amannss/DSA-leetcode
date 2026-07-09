class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false ;
        int n = word1.length() ;
        vector<int > vec1(26 , 0 ) ;
        vector<int> vec2(26 , 0) ;
        for(int i =0;i<n;i++)
        {
            vec1[word1[i] - 'a']++ ;
            vec2[word2[i] - 'a']++ ;
        }
        for(int i=0;i<26;i++)
        {
            if(vec1[i]!= 0 && vec2[i]!=0) continue ;
            else if (vec1[i]== 0 && vec2[i] == 0) continue ;
            else return false ;// any character not found in both strings
        }
    sort(vec1.begin() , vec1.end()) ;
    sort(vec2.begin() , vec2.end()) ;
        for(int i =0 ;  i <26 ;i++)
        {
            if(vec1[i] != vec2[i]) return false ;
        }
        return true ;
    }
};
class Solution {
public:
    int bestStartingPoint(string word , int n)
    {
        int i = 0 ; int j = 1 ;
        while(j < n )
        {
            int k = 0 ;
            while(j+k < n && word[i + k ] == word[j + k ])
            {
                k++ ;
            } 
            if(j+k < n  && word[i+ k] < word[j + k ]) // new best starting point found 
            {
                i = j ; 
                j =j + 1 ;
            }
            else j = j + k + 1 ;
        }
        return i ;
    }
    string answerString(string word, int numFriends) {
        int n = word.length() ;
        if(numFriends== 1 ) return word ;
        int i = bestStartingPoint(word , n ) ;
        int largestLengthPossible = n - (numFriends - 1) ;// all other frnds will be of min length that is 1
        int canTakePossible = min(largestLengthPossible , n - i ) ;// starting point se jitni length bachi hai = n - i 
        return word.substr(i , canTakePossible) ;
    }
};
class Solution {
public:
    int numberOfWays(string corridor) {
        int M = 1e9 + 7 ;
        int n = corridor.length() ;
        vector<int> indices_seats ;
        for(int i = 0 ; i < n ; i++)
        {
            if(corridor[i] == 'S') indices_seats.push_back(i);
        } 
        if(indices_seats.size()%2 != 0 || indices_seats.size() == 0) return 0 ;
        
        long long result = 1; 
        int prev =  indices_seats[1] ;
        for(int i = 2; i<indices_seats.size() ; i+=2)
        {  
            int length = indices_seats[i] - prev ;
            result = ( result * length ) % M ;
            prev = indices_seats[i+1] ;
        }
        return result ;
    }
};
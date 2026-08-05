class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin() , gas.end() , 0 ) ;
        int totalcost= accumulate(cost.begin() , cost.end() ,0 ) ;
        if(totalGas < totalcost ) return -1 ;
        int i = 0 ;int j = 0 ;
        int n = gas.size() ; 
        int totalgas = 0  ;
        while(i < n )
        {
            int g = gas[i] ;
            int c = cost[i] ;
            totalgas += g - c;
            if(totalgas < 0 )
            {
                j = i+1 ;
                totalgas = 0 ;
            }
            i++ ;
        }
        return j ;
    }
};
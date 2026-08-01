class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target <= startFuel ) return 0 ;
        // if(startFuel < stations[0][0] ) return -1 ;
        priority_queue<int> pq;
        int cnt = 0 ;int max_possible_covered = startFuel ;
        int i = 0 ;int n = stations.size() ;
        while(max_possible_covered < target )
        {
            while(i < n && stations[i][0]<= max_possible_covered)
            {
                pq.push(stations[i][1]) ;
                i++ ;
            }
            if(pq.empty() ) return -1 ;
            int top_dist = pq.top(); pq.pop() ;
            max_possible_covered += top_dist ;

            cnt++ ; 
        }
        return cnt ;
    }
};
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end() , greater<int>()) ;
        int n = cost.size() ;
        int sum =  0; int i = 0 ;
        while(i < n)
        {   
            if(n - i >= 2 )  {sum += cost[i] ;i++ ; sum+=cost[i] ;i++ ;}
            else sum+= cost[i++] ;
            i++ ;
        }
        return  sum ;
    }
};
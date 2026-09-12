class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int > pq ;
        unordered_set<int > st ; // min heap
        for(auto it : nums )
        {
            if(st.find(it) == st.end())
            {
                pq.push(it) ;
                st.insert(it) ;
            }
        }
        if(pq.size() < 3 ) return pq.top() ;
        int cnt = 1 ;
        while( cnt < 3)
        {
            pq.pop() ;cnt++ ;
        }
        int tops = pq.top() ;
        return tops ;
    }
};
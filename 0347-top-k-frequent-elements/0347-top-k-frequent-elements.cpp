class Solution {
public:
typedef pair<int , int> p ;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > mp ;
        for(auto it : nums) mp[it]++ ;
        priority_queue< p , vector<p> , greater<p>> pq ;
        for(auto it : mp)
        {
            pq.push({it.second ,it.first }) ;
            if(pq.size() > k ) pq.pop();
        }
        vector<int > result ;
        while(!pq.empty())
        {
            p tops = pq.top() ;
            pq.pop() ;
            result.push_back(tops.second) ;
        }
        return result ;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int > mp ;
        priority_queue<int , vector<int>> pq; // max heap
        for(auto it : tasks) mp[it]++ ;
        for(auto it : mp) pq.push(it.second) ;
        int cnt = 0 ;
        while(!pq.empty())
        {
            vector<int> freq ;
            int k = n +1 ;
            while(k>0 && !pq.empty())
            {
                int f = pq.top() ;pq.pop() ;
                f--;
                if(f > 0) freq.push_back(f) ;
                cnt++;
                k-- ;
            }
            if(!pq.empty() || !freq.empty()) // not last words so insert idle 
            {   
                cnt+= k;
            }
            for(auto it : freq) pq.push(it) ;
        }
        return cnt  ;
    }
};
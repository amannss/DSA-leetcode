class Solution {
public:
typedef pair<int , int > p ;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size() ;
        for(int i= 0 ; i < n;i++)
        {
            tasks[i].push_back(i) ;
        }
        sort(tasks.begin() , tasks.end() ) ;
        priority_queue< p , vector<p> , greater <p> > pq ; // min heap
        int i =0 ;
        vector<int> result ;
        long long  time = 0; 
        while(i < n || !pq.empty() )
        {
            if(pq.empty())
            {
                time = max(time ,(long long ) tasks[i][0]) ;// direct jump to first enque time 
            }
            while(i < n && time >= tasks[i][0]) 
            {
                pq.push({tasks[i][1] , tasks[i][2]}) ;// processing time , i 
                i++ ;
            } 
            // not use cpu if not busy 
            if(!pq.empty())
            {
                p tops = pq.top() ; pq.pop() ;
                time = time + tops.first ; // abhi jis time par hai + processing time 
                result.push_back(tops.second) ; // index
            }
        }
        return result ;
    }
};
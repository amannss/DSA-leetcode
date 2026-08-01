class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b)
        {   
            if(a[1] == b[1]) return a[0] < b[0] ;
            return a[1] < b[1] ;
        }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size() ;int i = 0 ;
        sort(courses.begin() , courses.end() , cmp ) ;
        priority_queue<int> pq ;// max heap
        int total = 0 ;
        while(i < n)
        {
            int x= courses[i][0] ;
            int y= courses[i][1] ;
            if(( total + x) <= y ) 
            {   
                total+= x ;
                pq.push(x) ;
            }
            else
            {
                if(!pq.empty() && x < pq.top())
                {
                    int val = pq.top();pq.pop() ;
                    total-=val ;
                    total+=x ;
                    pq.push(x) ;
                }
            }
            i++ ;
        }
        return pq.size() ;
    }   
};
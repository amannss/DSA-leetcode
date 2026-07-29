class Solution {
public:
typedef pair<int , int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size() ;
        auto cmp =[](p a, p b)
        {
            if(a.first == b.first ) // value same 
                return a.second < b.second ;
            return a.first < b.first ;
        };
        priority_queue< p,vector<p> , decltype(cmp) > pq ;
        for(int i =  0 ; i < n ;i++)
        {
            int val = arr[i] - x ;
            val = abs(val) ;
            pq.push({val , arr[i]}) ;
            if(pq.size() > k) pq.pop() ;
        }
        vector<int> vec ;
        while(!pq.empty())
        {
            p x = pq.top() ;
            pq.pop() ;
            vec.push_back(x.second) ;
        }
        sort(vec.begin() , vec.end() ) ;
        return vec ;
        
    }
};  
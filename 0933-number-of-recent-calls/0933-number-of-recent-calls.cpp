class RecentCounter {
public:
vector<int>vec ;
int i = 0; 
    RecentCounter() {
        
    }
    
    int ping(int t) {
        vec.push_back(t) ;
        int n= vec.size() ;
        int start = t - 3000 ;
        while(vec[i] < start )
        {
            i++ ;
        }
        return n - i ;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
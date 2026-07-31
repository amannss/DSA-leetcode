class MedianFinder {
public:
priority_queue<int , vector<int >> max_heap ;
priority_queue<int , vector<int> , greater<int >> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() == 0 ) 
        {
            max_heap.push(num) ; 
            return ;
        }
        if( num > max_heap.top()) min_heap.push(num) ;
        else max_heap.push(num) ;

        int n1 = max_heap.size() ;
        int n2 = min_heap.size() ;

        if(n2 > n1)
        {
            int t = min_heap.top() ; min_heap.pop() ;
            max_heap.push(t) ;
        }
        else if(n1 - n2 >1)
        {
            int t = max_heap.top() ; max_heap.pop() ;
            min_heap.push(t) ;
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }

        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
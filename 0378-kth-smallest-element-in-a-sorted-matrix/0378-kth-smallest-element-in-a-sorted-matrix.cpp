class Solution {
public:
typedef pair<int , pair<int , int>> p ;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 1 ) return matrix[0][k-1] ;
        priority_queue< p , vector<p> , greater<p>> pq ;
        int n = matrix.size() ; // row
        int m = matrix[0].size() ; // col
        for(int i = 0 ;i< n ;i++)
        {
            pq.push({matrix[i][0] , {i, 0}}); // val , row ,col
        } 
        while(k != 1  && !pq.empty())
        {
            p x = pq.top() ;
            pq.pop() ;
            int val = x.first ;
            int r = x.second.first ;
            int c = x.second.second;
            int nextr = r ;
            int nextc = c + 1 ;
            if(nextc < m)
                pq.push({matrix[nextr][nextc] , {nextr , nextc }}) ;     
                // 
            k-- ;
        }
        p x =pq.top() ;
        return x.first ;
    }
};
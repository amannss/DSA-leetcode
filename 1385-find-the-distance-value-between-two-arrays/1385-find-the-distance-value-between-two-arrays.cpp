class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size() ;
        int n2= arr2.size() ;
        int ans=  0 ;

        for(int i =0;i<n1;i++){
            int a = arr1[i] ;
            int cnt = 0 ;
            for(int j = 0  ; j < n2 ;j++){
                int b =  arr2[j] ;
                int rem = abs(a - b) ;
                if(rem <= d) break;
                cnt++ ;
            }

            if(cnt == n2) ans++ ;
        }

        return ans ; 
    }
};
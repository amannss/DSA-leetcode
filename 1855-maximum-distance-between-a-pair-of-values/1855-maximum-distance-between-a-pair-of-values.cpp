class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i ,j ; i =0 ; j=0 ;
        int n1= nums1.size()  ; int maxi = 0;
        int n2 = nums2.size() ;
        while(i < n1 && j < n2)
        {
            if(nums1[i] <= nums2[j])
            {
                maxi = max(maxi , j -i ); 
                j++ ;
            }
            else if(i<j)
            {
                i++ ;
            }
            else { i++ ; j++ ;} ;
        }
        return maxi ;
    }
};
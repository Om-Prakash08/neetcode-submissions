class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int n=nums1.size();
           int m=nums2.size();
           if(n>m){
            return findMedianSortedArrays(nums2,nums1);
           }
           int l=0, r=n;
           while(l<=r){
               int mid= l + (r-l)/2;
               int leftx = mid==0? INT_MIN: nums1[mid-1];
               int rightx = mid==n? INT_MAX: nums1[mid];
               int mid_ = (n+m+1)/2 - mid;
               int lefty = mid_==0? INT_MIN: nums2[mid_-1];
               int righty = mid_==m? INT_MAX: nums2[mid_];
               if(leftx>righty)
                r = mid -1;
               else if(lefty>rightx)
                l = mid + 1;
               else{
                if((n+m)%2)
                  return max(leftx,lefty);
                else
                  return (max(leftx,lefty)+min(rightx,righty))/2.0;
               }
           } 
           return 0;
    }
};
 
class Solution {
public:
    int findMin(vector<int> &arr) {
        if(arr.size()==1)
          return arr[0];
        int l = 0, r =arr.size()-1;
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(mid==0){
              if(arr[mid]>arr[mid+1])
                 return arr[mid+1];
              else 
                 l = mid+1;
            }
            else if(mid==arr.size()-1){
              if(arr[mid]<arr[mid-1])
                 return arr[mid];
              else 
                 r = mid-1;
            }
            else if(arr[mid]<arr[mid-1])
              return arr[mid];
            else if(arr[mid]>arr[mid+1])
              return arr[mid+1];
            else if(arr[mid]>arr[0])
              l = mid+1;
            else
              r = mid -1;
        }
        return arr[0];
    }
};

class Solution {
public:
    bool valid(vector<int>&piles, int h, int mid){
         int count = 0;
         for(int x: piles){
            count += (x+mid-1)/mid;
         }
         return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=1;
        int n=piles.size();
        for(int x: piles){
            r = max(r,x);
        }
        int ans = r;
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(valid(piles,h,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l,r;
        int n = height.size();
        if (n == 0) return 0;
        l.push_back(height[0]);
        r.push_back(height[n-1]);
        for(int i=1;i<n;i++){
            l.push_back(max(l[i-1],height[i]));
        }
        for(int j=n-2;j>=0;j--){
            r.push_back(max(r[n-j-2],height[j]));
        }
        reverse(r.begin(),r.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans += (min(l[i],r[i])-height[i]);
        }
        return ans;
    }
};

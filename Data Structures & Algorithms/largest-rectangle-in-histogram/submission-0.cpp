class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftb(n,0), rightb(n,0);
        for(int i=0;i<n;i++){
            leftb[i] = i;
            rightb[i] = i;
        }
        stack<int>st;
        for(int i=0;i<n;i++){
            int curr = i;
            while(st.size() && heights[st.top()]>=heights[i]){
                curr = st.top();
                st.pop();
            }
            st.push(i);
            leftb[i] = leftb[curr];
        }
        st = {};
        for(int i=n-1;i>=0;i--){
            int curr = i;
            while(st.size() && heights[st.top()]>=heights[i]){
                curr = st.top();
                st.pop();
            }
            st.push(i);
            rightb[i] = rightb[curr];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(rightb[i]-leftb[i]+1));
            cout<<rightb[i]<<' '<<leftb[i]<<endl;
        }
        return ans;
    }
};

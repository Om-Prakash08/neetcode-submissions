class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int>temp(3,0);
        for(int i=0;i<n;i++){
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            int x = target[0];
            int y = target[1];
            int z = target[2];
            if(a<=x&&b<=y&&c<=z){
              temp[0]= max(temp[0],a);
              temp[1]= max(temp[1],b);
              temp[2]= max(temp[2],c);
            }
        }
        return temp[0]==target[0]&&temp[1]==target[1]&&temp[2]==target[2];
    }
};

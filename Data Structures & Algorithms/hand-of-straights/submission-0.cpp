class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;
        map<int, int> mp;
        for (int a : hand) {
            if (mp.find(a) == mp.end())
                mp[a] = 1;
            else
                mp[a]++;
        }
        for(int i=0;i<n/groupSize;i++){
            int lower = mp.begin()->first;
            int a = lower;
            for(int k=0;k<groupSize;k++){
                if(mp.find(a)==mp.end())
                 return false;
                if(mp[a]==1)
                 mp.erase(a);
                else
                 mp[a]--;
                a++;
            }
        }
        return true;
    }
};

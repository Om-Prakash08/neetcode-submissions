#include<unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int i: nums){
            if(m.find(i)!=m.end())
              return true;
            else
              m.insert(i);
        }
        return false;
    }
};
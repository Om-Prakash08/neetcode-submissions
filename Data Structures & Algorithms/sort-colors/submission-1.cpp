class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0)
         return ;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                if(i!=j){
                    swap(nums[i],nums[j]);
                }
                i++;
                j++;
            }
            else
              j++;
        }
        j=i;
        while(j<nums.size()){
            if(nums[j]==1){
                if(i!=j){
                    swap(nums[i],nums[j]);
                }
                i++;
                j++;
            }
            else 
             j++;
        }
    }
};
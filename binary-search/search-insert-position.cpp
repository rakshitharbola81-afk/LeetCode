class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return i;
            }
            else{
                if(target<nums[i]){
                    return i;
                }
            }
        }
        return i;
    }
};
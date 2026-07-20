class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>ans(n);
        int left=0,right=n-1,k=n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[k--]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[k--]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};
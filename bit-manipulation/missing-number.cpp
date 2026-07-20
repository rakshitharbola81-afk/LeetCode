class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int nsum=n*(n+1)/2;
        int sum=0;
        int missing;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        missing=nsum-sum;
        return missing;
    }
};
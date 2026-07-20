class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int longest=1;
        int last_smaller=INT_MIN;
        int cnt_curr=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==last_smaller){
                cnt_curr+=1;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
                cnt_curr=1;
                last_smaller=nums[i];
            }
            longest=max(longest,cnt_curr);
        }
        return longest;
    }
};
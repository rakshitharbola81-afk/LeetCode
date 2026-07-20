class Solution {
public:
    void findSubsets(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&a)
    {
        int n=a.size();
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
            if(i!=ind && a[i]==a[i-1])continue;
            ds.push_back(a[i]);
            findSubsets(i+1,ds,ans,a);
            ds.pop_back();
        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,ds,ans,nums);
        return ans;
    }
};
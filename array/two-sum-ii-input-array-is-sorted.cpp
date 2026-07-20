class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0,right=numbers.size()-1;
        vector<int> arr;
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum==target){
                arr.push_back(left+1);
                arr.push_back(right+1);
                return arr;
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        return arr;
    }
};
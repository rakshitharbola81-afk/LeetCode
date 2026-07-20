class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int> maxHeap;

    for (int x : nums)
        maxHeap.push(x);

    for (int i = 1; i < k; i++)
        maxHeap.pop();

    return maxHeap.top();
}
    
};
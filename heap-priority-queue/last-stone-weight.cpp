class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>maxHeap;

        for(int i=0;i<n;i++){
            maxHeap.push(stones[i]);
        }
        int first,second;
        while(n>1){
            first=maxHeap.top();
            maxHeap.pop();
            second=maxHeap.top();
            maxHeap.pop();
            n-=2;
            if(first-second>0){
                maxHeap.push(first-second);
                n+=1;
            }
        }
        if(!maxHeap.empty()){
            return maxHeap.top();
        }
        return 0;
    }
};
class Solution {
public:
    bool possible(vector<int>&arr,int day,int m, int k){
        int n=arr.size();
        int cnt=0;
        int bouq=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                bouq+=(cnt/k);
                cnt=0;
            }
        }
        bouq+=(cnt/k);
        return bouq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX,maxi=INT_MIN;
        int n=bloomDay.size();
        for(int i=0;i<bloomDay.size();i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
        }
        int low=mini;
        int high=maxi;
        if((long long)m * k > bloomDay.size()) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
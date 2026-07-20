class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(a[0]!=a[1])return a[0];
        if(a[n-1]!=a[n-2])return a[n-1];
        int low=1,high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]!=a[mid+1] && a[mid]!=a[mid-1])return a[mid];
            if((mid%2==1 && a[mid-1]==a[mid])||(mid%2==0 && a[mid]==a[mid+1])){
                low=mid+1;
            }
            else high=mid-1;
        }
        return -1;
    }
};
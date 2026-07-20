class Solution {
public:

    long long time(vector<int>& arr, int speed, int n){
        long long totalhour = 0;

        for(int i = 0; i < n; i++){
            totalhour += (arr[i] + (long long)speed - 1) / speed;
        }
        return totalhour;
    }

    int maxel(vector<int>& arr, int n){
        int maxi = arr[0];
        for(int i = 1; i < n; i++){
            if(maxi < arr[i]){
                maxi = arr[i];
            }
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int low = 1;
        int high = maxel(piles, n);

        while(low <= high){

            int mid = low + (high - low) / 2;

            long long totalhours = time(piles, mid, n);

            if(totalhours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int n=s.size();
        int right=n-1;
        while(left<=right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> freq(26, 0);
        int distinctCount = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (freq[idx] == 0) {
                distinctCount++;
            }
            freq[idx]++;

            int len = i + 1;
            if (distinctCount == len % 3) {
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            mpp[s[j]]++;
            maxFreq = max(maxFreq, mpp[s[j]]);

            while ((j - i + 1) - maxFreq > k) {
                mpp[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};
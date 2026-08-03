class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int count = 0;

        int start = 0;
        int minLen = INT_MAX;

        vector<int> window(128, 0);

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];
            window[ch]++;

            if (window[ch] <= need[ch])
                count++;

            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char c = s[left];
                window[c]--;

                if (window[c] < need[c])
                    count--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
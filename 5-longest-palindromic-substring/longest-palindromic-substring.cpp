class Solution {
public:
    string longestPalindrome(string s) {

        if (s.size() <= 1)
            return s;

        auto expand_from_center = [&](int left, int right) -> string {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            string pali1 = expand_from_center(i, i);      // Odd length
            string pali2 = expand_from_center(i, i + 1);  // Even length

            string longer = (pali1.size() > pali2.size()) ? pali1 : pali2;

            if (longer.size() > ans.size())
                ans = longer;
        }

        return ans;
    }
};
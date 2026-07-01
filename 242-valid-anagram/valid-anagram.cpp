class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> s_freq(26, 0), t_freq(26, 0);
        for(char i:s){
            s_freq[i-'a']++;
        }
        for(char i:t){
            t_freq[i-'a']++;
        }
        return s_freq==t_freq;
    }
};
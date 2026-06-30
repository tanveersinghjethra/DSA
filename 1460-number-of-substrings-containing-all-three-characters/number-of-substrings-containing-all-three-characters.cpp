class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0,left=0,right=0;
        int freq[3]={0};
        for(int right=0;right<n;right++){
            freq[s[right]-'a']++;
            while(freq[0]&&freq[1]&&freq[2]){
                ans+=(n-right);
                freq[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};
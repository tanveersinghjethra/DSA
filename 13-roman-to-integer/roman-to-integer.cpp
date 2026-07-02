class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int perv=0,ans=0;
        for(char c:s){
            int current=roman[c];
            if(current>perv){
                ans+=current-2*perv;
                }
            else {
                ans+=current;
                }
            perv=current;
        }
        return ans;
    }
};
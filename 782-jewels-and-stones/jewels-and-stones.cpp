class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(char c:jewels){
            for(char d:stones){
                if(c==d){ans++;}
            }
        }
        return ans;
    }
};
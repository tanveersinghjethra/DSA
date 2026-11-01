class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find the min val and then find sumof(every element-minval)
        int n=nums.size();
        int mini=nums[0];
        for(int num:nums){
            if(num<mini){
                mini=num;
            }
        }
        int moves=0;
        for(int ele:nums){
            moves+=(ele-mini);
        }
        return moves;
    }
};
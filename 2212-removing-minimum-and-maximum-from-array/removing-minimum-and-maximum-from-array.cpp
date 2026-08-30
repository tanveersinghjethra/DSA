class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int mini=nums[0];
        int maxi=nums[0];
        int maxi_index=0;
        int mini_index=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxi_index=i;
            }
            else if(nums[i]<mini){
                mini=nums[i];
                mini_index=i;
            }
        }
        int left=min(mini_index,maxi_index);
        int right=max(mini_index,maxi_index);
        int op1=right+1;//deletion from left
        int op2=n-left;//deletion from right
        int op3=(left+1)+(n-right);//deletion from both the ends
        return min({op1,op2,op3});
    }
};
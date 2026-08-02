class Solution {
public:

    int fn(vector<int>& arr,int goal){
        if(goal<0)return 0;
        int left=0,right=0,sum=0,cnt=0;
        while(right<arr.size()){
            sum+=arr[right];
            while(sum > goal){
                sum=sum-arr[left];
                left++;
            }
            cnt=cnt+(right-left+1);
            right++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fn(nums,goal)-fn(nums,goal-1);
    }
};
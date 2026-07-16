class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        vector<int>prefixGcd(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum=0;
        int left=0,right=n-1;
        while(left<right){
            sum+=gcd(prefixGcd[left++],prefixGcd[right--]);
        }
        return sum;
    }
};
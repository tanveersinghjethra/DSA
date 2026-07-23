class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        //brute
        // unordered_set<int>st;//this will only take unique elements
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         for(int k=j;k<n;k++){
        //             int xors=nums[i]^nums[j]^nums[k];
        //             st.insert(xors);
        //         }
        //     }
        // }
        // return st.size();

        int n=nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int ans = 1;
        while (ans <= n) {
            ans =ans*2;
        }

        return ans;
    }
};
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<int,int> mpp;
        //     for(int j=i;j<n;j++){
        //         mpp[nums[j]]++;

        //         if(mpp.size()==k) ans++;
        //         if(mpp.size()>k) break;
        //     }
        // }
        
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
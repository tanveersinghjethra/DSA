class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        int duplicate = -1, missing = -1;

        for (int i = 1; i <= nums.size(); i++) {
            if (mp[i] >1)
                duplicate = i;
            else if (mp[i] < 1)
                missing = i;
        }

        return {duplicate, missing};
    }
};
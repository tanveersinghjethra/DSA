class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int current_element=k;
        while(seen.count(current_element)){
            current_element+=k;
        }
        return current_element;
    }
};
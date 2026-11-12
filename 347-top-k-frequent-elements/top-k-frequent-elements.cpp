class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>P;

        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        // we will use the min heap for the freq and remove the less frequent element if pq.size()>k
        priority_queue<P,vector<P>,greater<P>>pq;

        for(auto it: mp){
            int value=it.first;
            int freq=it.second;

            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
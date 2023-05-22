class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        
        for(auto& num: nums)
        {
            mp[num]++;
        }
        
        for(auto& it:mp)
        {
            pq.push({it.second,it.first});
        }
        
        while(k--)
        {
            int top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        return ans;
    }
};
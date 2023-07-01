class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto& it:s)
        {
            mp[it]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto& it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            for(int i = 0 ;i < it.first;i++)
            {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};
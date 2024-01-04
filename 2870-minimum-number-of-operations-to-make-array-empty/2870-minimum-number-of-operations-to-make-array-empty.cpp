class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& it:nums) mp[it]++;
        
        int res = 0;
        for (auto [_, cnt] : mp) {
            if (cnt == 1)
                return -1;
            res += cnt / 3 + (cnt % 3 > 0);
        }
        return res;
    }
};
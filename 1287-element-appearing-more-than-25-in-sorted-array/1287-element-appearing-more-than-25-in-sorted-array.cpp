class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto& num:arr)
        {
            mp[num]++;
            if(mp[num] > (0.25 * arr.size())) return num;
        }
        return -1;
    }
};
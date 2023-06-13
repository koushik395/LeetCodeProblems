class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        for(auto& row:grid)
        {
            mp[row]++;
        }
        int ans = 0;
        for(int i = 0;i < grid.size();i++)
        {
            vector<int> v;
            for(int j = 0;j < grid.size();j++)
            {
                v.push_back(grid[j][i]);
            }
            
            ans += mp[v];
        }
        return ans;
    }
};
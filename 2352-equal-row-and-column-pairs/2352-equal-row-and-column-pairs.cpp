class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        
        for(int i = 0;i < grid.size();i++)
        {
            string s;
            for(int j = 0;j< grid.size();j++)
            {
                s += to_string(grid[i][j]);
                s += "_";
            }
            mp[s]++;
        }
        
        int ans = 0;
        for(int i = 0;i < grid.size();i++)
        {
            string s;
            for(int j = 0;j < grid.size();j++)
            {
                s += to_string(grid[j][i]);
                s += "_";
            }
            
            ans += mp[s];
        }
        
        return ans;
    }
};
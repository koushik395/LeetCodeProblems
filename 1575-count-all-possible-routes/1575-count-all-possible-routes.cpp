class Solution {
public:
    int mod = 1e9+7;
    int find(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>> &dp)
    {
        if(dp[start][fuel] != -1) return dp[start][fuel];
        
        int paths = 0;
        if(start == finish) paths++;
        
        for(int i = 0;i < locations.size();i++)
        {
            if(i != start && abs(locations[i] - locations[start]) <= fuel)
            {
                paths += find(locations,i,finish,fuel - abs(locations[i] - locations[start]),dp);
                paths %= mod;
            }
        }
        return dp[start][fuel] = paths%mod;   
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        return find(locations,start,finish,fuel,dp);            
    }
};
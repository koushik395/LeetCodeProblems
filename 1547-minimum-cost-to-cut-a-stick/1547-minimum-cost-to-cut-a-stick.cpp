class Solution {
public:
    int Findcost(vector<vector<int>>& dp,vector<int>& cuts,int i,int j)
    {
        if(i > j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i ; ind <= j;ind++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) + Findcost(dp,cuts,i,ind-1) + Findcost(dp,cuts,ind+1,j);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0); 
        return Findcost(dp,cuts,1,cuts.size()-2);
    }
};
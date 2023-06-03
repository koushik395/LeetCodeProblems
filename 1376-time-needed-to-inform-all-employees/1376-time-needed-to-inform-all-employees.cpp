class Solution {
public:
    int dfs(vector<int> adj[],vector<int> &informTime,int manager)
    {
        int maxi = 0;
        int sum;
        for(auto& employee:adj[manager])
        {
            sum = informTime[manager] + dfs(adj,informTime,employee);
            maxi = max(maxi,sum);
        }
        return maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)       { 
        if(n == 1) return 0;
        
        vector<int> adj[n];
        for(int i =0 ;i < n;i++)
        {
            int manage = manager[i];
            int employee = i;
            if(manage != -1)
                adj[manage].push_back(employee);
        }
        
        return dfs(adj,informTime,headID);
    }
};
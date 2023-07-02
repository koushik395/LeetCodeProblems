class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        long long sum = 0;
        for(auto& it:roads)
        {
            int sn = it[0];
            int en = it[1];
            indegree[en]++;
            indegree[sn]++;
        }
        sort(indegree.begin(),indegree.end());
        for(int i = 0;i < n;i++)
        {
            sum += indegree[i] *1LL* (i+1);
        }
        
        return sum;
    }
};
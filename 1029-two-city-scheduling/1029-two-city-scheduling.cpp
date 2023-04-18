class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int total = 0;
        int sum = 0;
        int row = costs.size();
        vector<int> temp;
        for(int i = 0;i < row;i++)
        {
            temp.push_back(costs[i][1] - costs[i][0]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<row;i++)
        {
            total += costs[i][0];
        }
        for(int i=0;i<row/2;i++)
            sum+=temp[i];
        return total + sum;
    }
};
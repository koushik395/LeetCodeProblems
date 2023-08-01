class Solution {
public:
    int minimumCost(vector<int>& candies) {
        if(candies.size() <= 2) return accumulate(candies.begin(),candies.end(),0);
        int n = candies.size();
        sort(candies.begin(),candies.end());
        int i = n-1,cost = 0;
        while(i >= 0)
        {
            int j = i;
            while(j >= max(0, i - 1))
            {
                cost += candies[j];
                j--;
            }
            i -= 3;
        }
        return cost;
    }
};
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n,true);
        int max = *max_element(candies.begin(),candies.end());
        for(int i =0;i<n;i++)
        {
            int c = (extraCandies + candies[i]);
            if(c < max)
                ans[i] = false;
        }
        return ans;
    }
};
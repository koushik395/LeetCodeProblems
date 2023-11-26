class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles),end(piles));
        int n = piles.size();
        int ans = 0;
        for(int i = n/3;i < n;i+=2)
        {
            ans += piles[i];
        }
        return ans;
    }
};
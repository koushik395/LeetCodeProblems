class Solution {
public:
    int solve(vector<int>& nums, int visited, int& n, int op, vector<int>& memo)
    {
        if(memo[visited] != -1)
        {
            return memo[visited];
        }
        int maxScore = 0;
        for(int i=0; i<n-1; i++)
        {
            if(visited & (1 << i))
            {
                continue;
            }
            for(int j=i+1; j<n; j++)
            {
                if(visited & (1 << j))
                {
                    continue;
                }
                int newVisited = visited | (1 << i) | (1 << j);
                int currScore = op * __gcd(nums[i], nums[j]);
                int remainScore = solve(nums, newVisited, n, op+1, memo);
                maxScore = max(maxScore, currScore+remainScore);
            }
        }
        return memo[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo((1 << n), -1);
        return solve(nums, 0, n, 1, memo);
    }
};
class Solution {
public:
    int solve(vector<int>& nums, vector<bool>& visited, int& n, int op, unordered_map<vector<bool>, int>& hashMap)
    {
        if(hashMap.find(visited) != hashMap.end())
        {
            return hashMap[visited];
        }
        int maxScore = 0;
        for(int i=0; i<n-1; i++)
        {
            if(visited[i])
            {
                continue;
            }
            for(int j=i+1; j<n; j++)
            {
                if(visited[j])
                {
                    continue;
                }
                visited[i] = true;
                visited[j] = true;
                int currScore = op * __gcd(nums[i], nums[j]);
                int remainScore = solve(nums, visited, n, op+1, hashMap);
                maxScore = max(maxScore, currScore+remainScore);
                visited[i] = false;
                visited[j] = false;
            }
        }
        return hashMap[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_map<vector<bool>, int> hashMap;
        return solve(nums, visited, n, 1, hashMap);
    }
};
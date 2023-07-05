class Solution {
public:
    int n;
    vector<int> jumps = {-1,0,1};
    unordered_map<string,int> dp;
    bool solve(vector<int>& stones,int i,int prev)
    {
        if(i >= n) return false;
        if(i == n-1) return true;

        int curr = stones[i];
        string key = to_string(i)+"_"+to_string(prev);
        if(dp.find(key)!= dp.end()) return dp[key];

        for(auto& it: jumps)
        {
            int jump = prev + it;
            int val = curr + jump;
            auto idx = lower_bound(stones.begin()+i+1,stones.end(),val);
            if(idx != stones.end() && *idx == val)
            {
                int j = idx-stones.begin();
                if(solve(stones,j,jump))
                {
                    return true;
                }
            }
        }
        return dp[key] = false; 
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] > 1) return false;
        return solve(stones,1,1);
    }
};
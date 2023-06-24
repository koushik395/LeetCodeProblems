class Solution {
public:
    // RECURSION
    /*int n;
    int func(int ind,int sum1,int sum2,vector<int>& rods)
    {
        if(ind == n)
        {
            if(sum1 == sum2) return sum1;
            return 0;
        }
        
        int nottake = func(ind+1,sum1,sum2,rods);
        int takerod1 = func(ind+1,sum1 + rods[ind],sum2,rods);
        int takerod2 = func(ind+1,sum1,sum2 + rods[ind],rods);
        
        return max({nottake,takerod1,takerod2});
    }*/
    
    int dp[21][2 * 5000 + 1] , n;
    int func(int ind,int diff,vector<int>& rods)
    {
        if (ind == n) {
            if (diff == 0)return 0;
                return INT_MIN;
        }
        int &ans = dp[ind][diff + 5000];
        if (ans != -1) return ans;
        
        int nottake = func(ind + 1 , diff, rods);
        int takerod1 = rods[ind] + func(ind + 1 , diff +rods[ind],rods);
        int takerod2 = func(ind + 1 , diff - rods[ind],rods);
        
        return ans = max({nottake, takerod1, takerod2});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(dp , -1 , sizeof(dp));
        int ans = func(0, 0,rods);
        if (ans < 0)return 0;
        return ans;
    }
};
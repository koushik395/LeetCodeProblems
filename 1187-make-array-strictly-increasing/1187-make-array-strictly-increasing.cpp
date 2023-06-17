class Solution {
public:
    int helper(int i,int prev,map<pair<int,int>,int>&dp,vector<int>& arr1, vector<int>& arr2)
{
    if(i==arr1.size())
        return 0;
    if(dp.find({i,prev})!=dp.end())
        return dp[{i,prev}];
        
    int ans=INT_MAX/2;
    int id=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        
    if(arr1[i]>prev)
        ans=min(ans,helper(i+1,arr1[i],dp,arr1,arr2));
    if(id<arr2.size())
        ans=min(ans,helper(i+1,arr2[id],dp,arr1,arr2)+1);
    return dp[{i,prev}]=ans;
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int>dp;
        sort(arr2.begin(),arr2.end());
        int ans=helper(0,INT_MIN,dp,arr1,arr2);
        if(ans>=INT_MAX/2) return -1;
        return ans;
    }
};
class Solution {
public:
    long long findMin(vector<int>& nums, vector<int>& cost,long long& median)
    {
        long long res =  0;
        for(int i = 0;i < nums.size();i++)
        {
            res += abs(nums[i] - median) * cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> arr;
        long long sum = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum += cost[i];
            arr.push_back({nums[i],cost[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        long long median, total = 0, i = 0;
        while(total < (sum+1)/2 && i < nums.size())
        {
            total += arr[i].second;
            median = arr[i].first;
            i++;
        }
        
        return findMin(nums,cost,median);
    }
};
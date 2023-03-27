class Solution {
public:
    bool isPossible(vector<int> &nums,int m,long long mid)
    {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans += sqrt(mid/nums[i]);
        }
        if(ans < m)
            return false;
        return true;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = -1;
        long long low,high,mid;
        low = 0;
        high = 100 * 1e6*1e6;
        while(low <= high)
        {
            mid = ((low + high)>>1);
            if(isPossible(ranks,cars,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
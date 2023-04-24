class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            int gcd = nums[i];
            if(gcd == k)
                count++;
            for(int j=i+1;j<n;j++)
            {
                gcd = __gcd(gcd,nums[j]);
                if(gcd == k)
                    count++;
            }
        }
        return count;
    }
};
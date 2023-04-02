class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans = -1;
        sort(nums.begin(),nums.end());
        int gcd = *min_element(numsDivide.begin(),numsDivide.end());
        for(auto i:numsDivide)
        {
            gcd = __gcd(gcd,i);
        }
        for(int i = 0;i < nums.size();i++)
        {
            if(gcd%nums[i] == 0)
            {
                ans = i;
                break;
            }   
        }
        return ans;
    }
};
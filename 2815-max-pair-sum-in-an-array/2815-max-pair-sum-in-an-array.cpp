class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = -1,max_num[10] = {};
        for(auto& num:nums)
        {
            int max_d = 0;
            for(int x = num;x;x/=10)
            {
                max_d = max(max_d,x%10);
            }
            if(max_num[max_d])
            {
                res = max(res,max_num[max_d] + num);
            }
            max_num[max_d] = max(max_num[max_d],num);
        }
        
        return res;
    }
};
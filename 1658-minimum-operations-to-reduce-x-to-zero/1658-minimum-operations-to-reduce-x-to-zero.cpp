class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum1 = 0,sum2 = 0,len = 0;
        sum2 = accumulate(nums.begin(),nums.end(),0);
        
        sum2 -= x;
        
        if(sum2 == 0) return nums.size();
        
        for(int i = 0,j = 0;j < nums.size();j++)
        {
            sum1 += nums[j];
            
            while(i < nums.size() && sum1 > sum2) sum1 -= nums[i++];
            
            if(sum1 == sum2) 
            {
                len = max(len,j-i+1);
            }
        }
        if(!len) return -1;
        return nums.size()-len;
    }
};
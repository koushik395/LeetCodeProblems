class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)
        {
            int maxi = *max_element(nums.begin(),nums.end());
            return {maxi};
        }
        vector<int> ans;
        
        deque<int> dq;
        
        for(int i = 0;i < n;i++)
        {
            if(!dq.empty() && (i - dq.front() >= k))
            {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i - k + 1 >= 0)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
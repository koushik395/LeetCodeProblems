class Solution {
public:
    typedef pair<int,int> pp;
    long long findScore(vector<int>& nums) {
        priority_queue<pp ,vector<pp> , greater<pp>> pq;
        
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i < nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        while(!pq.empty())
        {
            int num = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(nums[ind] != -1)
            {
                sum += nums[ind];
                if(ind - 1>= 0) nums[ind-1] = -1;
                if(ind + 1 < n) nums[ind+1] = -1;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        priority_queue<int> pq;
        int n = nums[0].size();
        vector<int> dist(n,-1);
        
        for(auto& x:nums)
        {
            int ind = 0;
            for(int i = 0;i < x.size();i++)
            {
                pq.push(x[i]);
            }
            
            while(!pq.empty())
            {
                int top = pq.top();
                pq.pop();
                if(dist[ind] < top)
                {
                    dist[ind] = top;
                }
                ind++;
            }
            
        }
        
        int sum = 0;
        for(int i =0; i < n;i++)
        {
            sum += dist[i];
        }
        return sum;
    }
};
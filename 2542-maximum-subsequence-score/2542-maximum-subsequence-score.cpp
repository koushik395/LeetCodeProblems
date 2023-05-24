class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        vector<pair<int,int>> newarr(nums1.size());
        
        for(int i = 0;i < nums1.size();i++)
                newarr[i] = make_pair(nums2[i],nums1[i]);
        
        sort(newarr.begin(),newarr.end(),greater<pair<int,int>>());
        long long sum = 0,ans = 0;
        
        for(auto& [mul,score]: newarr)
        {
            cout << mul << " "<< score << endl;
            minheap.push(score);
            sum += score;
            if (minheap.size() > k) {
                sum -= minheap.top();
                minheap.pop();
            }
            if (minheap.size() == k)
                ans = max(ans, sum * mul);
        }
        
        return ans;
    }
};
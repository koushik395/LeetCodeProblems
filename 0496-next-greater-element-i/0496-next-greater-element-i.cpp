class Solution {
public:
    void solve(vector<int> &arr, int n,vector<int> &ans)
    {
        stack<long long> s;
        n--;
        s.push(-1);
        for(int i=n;i>=0;i--)
        {
            while(s.top()!= -1 && s.top() <=arr[i])
                s.pop();
            ans[i] = s.top();
            s.push(arr[i]);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(),n1 = nums1.size();
        vector<int> ans(n);
        solve(nums2,n,ans);
        vector<int> res;
        for(int i = 0;i < n1;i++)
        {
            int index = find(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();
            res.push_back(ans[index]);
        }
        return res;
    }
};
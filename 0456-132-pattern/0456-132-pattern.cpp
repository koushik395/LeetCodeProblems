class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int s2 = INT_MIN;
        stack<int> s3;
        for(int i = n-1;i >= 0;i--) {
            int s1 = nums[i];
            if (s2 > s1) {
                return true;
            } else {
                while (!s3.empty() && s1 > s3.top()) {
                    s2 = s3.top(); s3.pop();
                }
            }
            s3.push(s1);
        }
        return false;
    }
};
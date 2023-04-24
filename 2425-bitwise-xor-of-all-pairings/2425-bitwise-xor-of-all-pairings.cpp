class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        if(m&1){
            for(auto it : nums1) ans = (ans^it);
        }
        if(n&1){
            for(auto it : nums2) ans = (ans^it);
        }
        return ans;
    }
    
};
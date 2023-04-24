class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),n2 = nums2.size(),ans=0,ans1=0;
        for(auto& num:nums1)
            ans^=num;
        for(auto& num:nums2)
            ans1^=num;
        if(n&1 && n2&1)
            return ans^ans1;
        if((n&1)==0 && (n2&1)==1)
            return ans;
        if((n&1)==1 && (n2&1)==0)
            return ans1;
        return 0;
    }
    
};
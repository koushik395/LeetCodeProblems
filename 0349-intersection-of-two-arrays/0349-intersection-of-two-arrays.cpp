class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> result;
        int i = 0,j=0;
        int n = nums1.size(),m = nums2.size();
        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j]) i++;
            else if(nums2[j] < nums1[i]) j++;
            else
            {
                result.push_back(nums1[i]);
                i++,j++;
                while(i < n && nums1[i]==nums1[i-1]) i++;
                while(j < m && nums2[j] == nums2[j-1])j++;
            }
        }
        return result;
    }
};
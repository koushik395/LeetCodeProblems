class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        for(int i = 0;i<n;i++)
            nums1.push_back(0);
        int low = m -1,end = (m+n) - 1, high = n - 1;
        
        while((high >= 0) && (low >= 0))
        {
            if(nums2[high] >= nums1[low])
            {
                nums1[end] = nums2[high];
                high--;
            }
            else
            {
                nums1[end] = nums1[low];
                low--;
            }
            end--;
        } 
        while(high>=0)
        {
            nums1[end] = nums2[high];
            end--;
            high--;
        }
        double ans;
        int size = m+n;
        if(size&1)
            ans = nums1[size>>1];
        else
            ans = ((nums1[(size>>1)-1] + nums1[(size>>1)])*1.0) / 2;
        
        return ans;
    }
};
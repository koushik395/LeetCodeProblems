// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // if(isBadVersion(n))
        // {
        //     return firstBadVersion(--n);
        // }
        // return n+1;
        
        int low = 0,high = n,mid;
        while(low < high)
        {
            mid = low + (high - low)/2;
            if(isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
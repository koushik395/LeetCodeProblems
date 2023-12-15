class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1,high = sqrt(num);
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mid*mid == num) return true;
            else if(mid < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
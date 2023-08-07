class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0,high = (row*col)-1,mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            int ele = matrix[mid/col][mid%col];
            if(ele == target)
                return 1;
            else if(ele < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
        }
};
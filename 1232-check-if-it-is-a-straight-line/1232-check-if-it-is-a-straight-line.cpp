class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        int dY = nums[1][1] - nums[0][1];
        int dX = nums[1][0] - nums[0][0];     
        for( int i=2; i < nums.size(); i++ ) {
            auto p = nums[i];
            if( dX*(p[1] - nums[0][1]) != dY*(p[0] - nums[0][0]) )
                return false;
        }
        return true;
    }
};
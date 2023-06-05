class Solution {
public:
    pair<int,int> distance(vector<int>& first,vector<int>& second)
    {
        int x1 = first[0],y1 = first[1],x2 = second[0],y2 = second[1];
        return {(y2-y1),(x2-x1)};
    }
    bool checkStraightLine(vector<vector<int>>& nums) {
        pair<int,int> firstDist = distance(nums[0],nums[1]);
        int dy = firstDist.first;
        int dx = firstDist.second;
        
        for(int i=2;i < nums.size();i++)
        {
            pair<int,int> nextDist =  distance(nums[0],nums[i]);
            if(dx*(nextDist.first) != dy*(nextDist.second)) return false;
        }
        return true;
    }
};
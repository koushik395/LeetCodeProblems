class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> area;
        int maxi = 0;
        for(auto& it:points)
        {
            area.insert(it[0]);
        }
        for(auto it = next(begin(area)); it != end(area);it++)
        {
            maxi = max(maxi,*it - *prev(it));
        }
        return maxi;
    }
};
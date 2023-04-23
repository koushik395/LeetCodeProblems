class Solution {
public:
    bool static compare(vector<int>& a,vector<int>& b)
    {
        return a[1] < b[1];   
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(),points.end(),compare);
        
        int prev = points[0][1];
        for(int i = 1;i<points.size();i++)
        {
            if(prev >= points[i][0])
                count++;
            else
                prev = points[i][1];
        }
        return points.size()-count;
    }
};
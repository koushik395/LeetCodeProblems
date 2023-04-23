class Solution {
public:
    bool static compare(vector<int>& a,vector<int>& b)
    {
        return a[1] < b[1];   
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end(),compare);
        
        int prev = intervals[0][1];
        for(int i = 1;i<intervals.size();i++)
        {
            if(prev > intervals[i][0])
                count++;
            else
                prev = intervals[i][1];
        }
        return count;
    }
};
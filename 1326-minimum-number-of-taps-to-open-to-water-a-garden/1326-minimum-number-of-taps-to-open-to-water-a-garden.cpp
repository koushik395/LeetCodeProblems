class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,0);
        
        for(int i = 0;i < n+1;i++)
        {
            int left = max(0,i - ranges[i]);
            startEnd[left] = max(startEnd[left],min(n,i+ranges[i]));
        }
        
        int taps = 0;
        int maxend = 0;
        int currend = 0;
        for(int i = 0;i <= n;i++)
        {
            if(i > maxend) return -1;
            if(i > currend)
            {
                taps++;
                currend = maxend;
            }
            maxend = max(maxend,startEnd[i]);
        }
        return taps;
    }
};
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>&b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(),pairs.end(),cmp);
        
        int cnt = 1;
        int sp = pairs[0][0],ep = pairs[0][1];
        for(int i = 1;i < pairs.size();i++)
        {   
            int newsp = pairs[i][0];
            int newep = pairs[i][1];
            if(ep < newsp)
            {
                cnt++;
                sp = newsp;
                ep = newep;
            }
        }
        return cnt;
    }
};
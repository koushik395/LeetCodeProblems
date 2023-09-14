class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz =  ratings.size();
        vector<int> maxi(sz,1);
        
        int ans = 0;
        for(int i = 1;i < sz;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                maxi[i] = maxi[i-1] + 1; 
            }
        }
        
        for(int i = sz-1;i > 0;i--)
        {
            if(ratings[i-1] > ratings[i])
            {
                maxi[i-1] = max(maxi[i]+1,maxi[i-1]);
            }
        }
        
        ans = accumulate(maxi.begin(),maxi.end(),0);
        return ans;
    }
};
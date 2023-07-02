class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        
        vector<pair<int,int>> arr;
        for(int i = 0;i < score.size();i++)
        {
            arr.push_back({score[i],i});
        }
        
        sort(arr.rbegin(),arr.rend());
        
        int k = 4;
        for(int i = 0;i < arr.size();i++)
        {
            if(i <3)
            {
                if(i == 0) ans[arr[i].second] = "Gold Medal";
                else if(i == 1) ans[arr[i].second] = "Silver Medal";
                else ans[arr[i].second] = "Bronze Medal";
                continue;
            }
            
            ans[arr[i].second] = to_string(k);
            k++;
        }
        
        return ans;
    }
};
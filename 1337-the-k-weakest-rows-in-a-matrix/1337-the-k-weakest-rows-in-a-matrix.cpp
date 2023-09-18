class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int row = mat.size(),col = mat[0].size();
        for(int i = 0;i < row;i++)
        {
            int numSoldiers = col - (lower_bound(mat[i].rbegin(),mat[i].rend(),1) - mat[i].rbegin()); 
            pq.push({numSoldiers,i});
        }
        
        vector<int> ans;
        while(k--)
        {
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};
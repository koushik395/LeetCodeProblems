class Solution {
public:
    int find(int k, vector<int> &ans,int i)
    {
        if(ans.size()==1)
            return ans[0];
        i = ((i + k)%ans.size());
        ans.erase(ans.begin()+i);
        return find(k,ans,i);
    }
    int findTheWinner(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(i);
        return find(k-1,ans,0);
    }
};
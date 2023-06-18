//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DSU {
    vector<int> rank, parent, size; 
public: 
    DSU(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u); 
        int ulp_v = findParent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u); 
        int ulp_v = findParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int> mp;
        for(int i = 0;i < n;i++)
        {
            for(int j = 1;j < accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end())
                {
                    mp[mail] = i;
                }
                else
                {
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto& it:mp)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0; i< n;i++)
        {
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            mergeMail[i].insert(mergeMail[i].begin(),accounts[i][0]);
            ans.push_back(mergeMail[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends
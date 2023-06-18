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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
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
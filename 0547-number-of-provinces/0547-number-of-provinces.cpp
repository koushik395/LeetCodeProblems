class Solution {
public:
    void makeSet(vector<int> &parent,vector<int> &rank,int n)
    {
      for(int i = 0;i < n;i++)
      {
        parent[i] = i;
        rank[i] = 0;
      }
    }

    int findParent(vector<int> &parent,int node)
    {
      if(parent[node] == node)
      {
        return node;
      }
      return parent[node] = findParent(parent, parent[node]);
    }

    void unionset(int u,int v,vector<int>& parent,vector<int> &rank)
    {
       u = findParent(parent, u);
       v = findParent(parent, v);

       if(rank[u] < rank[v])
       {
         parent[u] = v;
       }
       else if(rank[v] < rank[u])
       {
         parent[v] = u;
       }
       else{
         parent[v] = u;
         rank[u]++; 
       }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent,rank,n);
        
        for(int i = 0;i < n;i++)
        {
            int u = findParent(parent,i);
             for(int j = 0; j < n;j++)
             {
                 if(i!=j && isConnected[i][j])
                 {
                     int v = findParent(parent,j);
                     if(u!=v)
                     {
                         unionset(u,v,parent,rank);
                     }
                 }
             }
        }
        for(int i = 0;i<n;i++)
        {
            findParent(parent,i);
        }
        
        unordered_set<int> result(parent.begin(),parent.end());
        return result.size();
    }
};
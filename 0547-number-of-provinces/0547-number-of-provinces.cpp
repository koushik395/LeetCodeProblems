class Solution {
public:
    int count;
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
       if(u == v) return;
        
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
       count--; 
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        count  = n;
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent,rank,n);
        
        for(int i = 0;i < n;i++)
        {
             for(int j = i+1; j < n;j++)
             {
                 if(isConnected[i][j])
                 {
                    unionset(i,j,parent,rank);
                 }
             }
        }
        return count;\
    }
};
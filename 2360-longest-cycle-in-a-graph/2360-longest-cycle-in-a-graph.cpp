class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int v = edges.size();
        vector<int> indegree(v, 0);
        vector<bool> visited(v,false);
        int ans = -1;

        for (int i = 0; i < v; i++) {
            if(edges[i]!=-1)
                indegree[edges[i]]++;
        }

        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty())
        {
            int front = q.front();
            visited[front] = true;
            q.pop();
            int child = edges[front];
            if(child!=-1)
            {
                indegree[child]--;
                if(indegree[child]==0) q.push(child);    
            }  
        }
        //for cycle detection and taking the max cycle length
        for(int i=0;i<v;i++)
        {
           if(!visited[i])
           {
               int neighbour = edges[i];
               int count = 1;
               visited[i] = true;
               while(neighbour!=i)
               {
                   visited[neighbour] = true;
                   count++;
                   neighbour = edges[neighbour];
               }
               ans = max(ans,count);
           }
        }
    return ans;
    }
};
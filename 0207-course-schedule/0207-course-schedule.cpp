class Solution {
public:
    void calculate(vector<int> &indegree,vector<vector<int>> &adj,int child)
	{
	    for(auto& neighbour:adj[child])
	    {
	        indegree[neighbour]++;
	    }
	}
	int topoSort(int v, vector<vector<int>> &adj) 
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> indegree(v,0);
	    int count =0;
	    for(int i=0;i<v;i++)
	    {
	        calculate(indegree,adj,i);
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    while(q.size()!=0)
	    {
	        int front = q.front();
            count++;
	        ans.push_back(front);
	        q.pop();
	        for(auto& neighbour:adj[front])
	        {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
	        }
	    }
	   return count;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& v:prerequisites)
        {
            adj[v[1]].push_back(v[0]);
        }
        int ans = topoSort(n,adj);
        if(ans == n)
            return true;
        return false;
    }
};
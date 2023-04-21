class Solution {
public:
    void calculate(vector<int> &indegree,vector<vector<int>> &adj,int child)
	{
	    for(auto& neighbour:adj[child])
	    {
	        indegree[neighbour]++;
	    }
	}
	vector<int> topoSort(int v, vector<vector<int>> &adj) 
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
	        ans.push_back(front);
            count++;
	        q.pop();
	        for(auto& neighbour:adj[front])
	        {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
	        }
	    }
        if(count == v)
        {
            return ans;
        }
        return {};
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto& v:prerequisites)
        {
            adj[v[1]].push_back(v[0]);
        }
        return topoSort(n,adj);
    }
};
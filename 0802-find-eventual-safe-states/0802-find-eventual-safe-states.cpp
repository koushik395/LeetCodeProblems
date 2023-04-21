class Solution {
public:
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> outdegree(v, 0);
    vector<vector<int>> parent(v);
    vector<int> ans;

    for (int i = 0; i < v; i++) {
        for (int neighbour : graph[i]) {
            outdegree[i]++;
            parent[neighbour].push_back(i);
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(outdegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for(auto& child:parent[front])
        {
            if(child!=-1)
            {
                outdegree[child]--;
                if(outdegree[child]==0) q.push(child);   
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}

};
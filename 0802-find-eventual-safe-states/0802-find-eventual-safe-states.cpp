class Solution {
public:
    void isCyclic(vector<vector<int>>& graph, int node, vector<bool>& visited, unordered_map<int, vector<int>>& parent) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            parent[neighbor].push_back(node);
            isCyclic(graph, neighbor, visited, parent);
        } else {
            parent[neighbor].push_back(node); 
        }
    }
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> outdegree(v, 0);
    vector<int> ans;

    for (int i = 0; i < v; i++) {
        for (int neighbour : graph[i]) {
            outdegree[i]++;
        }
    }

    vector<bool> visited(v, false);
    unordered_map<int, vector<int>> parent;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            parent[i].push_back(-1);
            isCyclic(graph, i, visited, parent);
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
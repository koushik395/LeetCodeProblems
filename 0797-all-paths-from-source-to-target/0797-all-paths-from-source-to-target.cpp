class Solution {
public:
    void dfs(int node, int& dest, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, bitset<15>& visited)
    {
        if(node == dest)
        {
            ans.push_back(path);
            return;
        }
        for(int& neighbour: graph[node])
        {
            if(!visited[neighbour])
            {
                visited.set(neighbour);
                path.push_back(neighbour);
                dfs(neighbour, dest, graph, ans, path, visited);
                path.pop_back();
                visited.flip(neighbour);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int src = 0, dest = graph.size()-1;
        vector<int> path;
        bitset<15> visited;
        visited.set(src);
        path.push_back(src);
        dfs(src, dest, graph, ans, path, visited);
        return ans;
    }
};
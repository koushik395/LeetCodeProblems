class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& outdegree, vector<int>& color, int node, vector<int>& result) {
    color[node] = 1; // mark node as visiting
    for (int neighbour : graph[node]) {
        if (color[neighbour] == 1) // if neighbour is currently visiting, cycle detected
            return false;
        else if (color[neighbour] == 0) { // if neighbour is unvisited
            if (!dfs(graph, outdegree, color, neighbour, result)) // recursively visit neighbour
                return false; // if cycle detected in subtree, return false
        }
    }
    color[node] = 2; // mark node as visited
    result.push_back(node); // add to result as safe node
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> outdegree(v, 0);
    vector<int> color(v, 0); // 0: unvisited, 1: visiting, 2: visited
    vector<int> result;

    // Construct the graph and calculate outdegree
    for (int i = 0; i < v; i++) {
        for (int neighbour : graph[i]) {
            outdegree[i]++;
        }
    }

    // Perform DFS traversal to find safe nodes
    for (int i = 0; i < v; i++) {
        if (color[i] == 0 && dfs(graph, outdegree, color, i, result)) {
            // if node is unvisited and DFS returns true (no cycles)
            // then all nodes in subtree are safe nodes
        }
    }

    sort(result.begin(), result.end()); // sort the result in ascending order
    return result;
}



};
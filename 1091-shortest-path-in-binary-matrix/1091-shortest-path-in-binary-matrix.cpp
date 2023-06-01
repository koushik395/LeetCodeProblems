class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] == 1 || grid[n-1][m-1] == 1)
        {
            return -1;
        }
        auto isSafe = [&](int& x, int& y)
        {
            return x >= 0 && x < n && y >= 0 && y < m && !grid[x][y];
        };
        auto heuristic = [&](const int& x, const int& y)
        {
            return max(abs(n-1-x), abs(m-1-y));     // Max of Manhattan Distance from (x,y) -> (n, m)
        };
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0 + heuristic(0, 0), {0, 0}});
        result[0][0] = 0;
        while(!pq.empty())
        {
            int distHeuristic = pq.top().first;
            auto node = pq.top().second;
            int x = node.first;
            int y = node.second;
            int dist = distHeuristic - heuristic(x, y);
            if(x == n-1 && y == m-1)
            {
                return dist+1;
            }
            pq.pop();
            for(auto& dir: directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1]; 
                int wt = 1;
                if(isSafe(newX, newY) && dist + wt < result[newX][newY])
                {
                    result[newX][newY] = dist + wt;
                    pq.push({dist + wt + heuristic(newX, newY), {newX, newY}});
                }
            }
        }
        return -1;
    }
};
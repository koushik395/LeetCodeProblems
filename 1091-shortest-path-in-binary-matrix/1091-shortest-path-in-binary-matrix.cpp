class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] == 1)
        {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int level = 0;
        auto isSafe = [&](int& x, int& y)
        {
            return x >= 0 && x < n && y >= 0 && y < m && !grid[x][y];
        };
        while(!q.empty())
        {
            int qSize = q.size();
            for(int i=0; i<qSize; i++)
            {
                auto curr = q.front();
                int x = curr.first;
                int y = curr.second;
                if(x == n-1 && y == m-1)
                {
                    return level+1;
                }
                q.pop();
                for(auto& dir: directions)
                {
                    int newX = x+dir[0];
                    int newY = y+dir[1];
                    if(isSafe(newX, newY))
                    {
                        q.push({newX, newY});
                        grid[newX][newY] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
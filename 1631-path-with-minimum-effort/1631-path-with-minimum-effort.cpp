class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    typedef pair<int, pair<int, int>> P;
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        auto isSafe = [&](int& x, int& y)
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        pq.push({0, {0, 0}});
        result[0][0] = 0;
        while(!pq.empty())
        {
            int difference = pq.top().first;
            auto node = pq.top().second;
            int x = node.first;
            int y = node.second;
            if(x == n-1 && y == m-1)
            {
                return difference;
            }
            pq.pop();
            for(auto& dir: directions)
            {
                int newX = x+dir[0], newY = y+dir[1];
                if(isSafe(newX, newY))
                {
                int newEffort = max(difference,abs(heights[newX][newY] - heights[x][y]));
                    if(newEffort < result[newX][newY])
                    {
                        result[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});   
                    }
                }
            }
        }
        return 0;
    }
};
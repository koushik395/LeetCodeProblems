//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    typedef pair<int, pair<int, int>> P;
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        int srcx = source.first;
        int srcy = source.second;
        int desx = destination.first;
        int desy = destination.second;
        
        if(m == 0 || n == 0 || grid[srcx][srcy] == 0)
        {
            return -1;
        }
        auto isSafe = [&](int& x, int& y)
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        
        pq.push({0, {srcx,srcy}});
        result[srcx][srcy] = 0;
        while(!pq.empty())
        {
            int dist = pq.top().first;
            auto node = pq.top().second;
            int x = node.first;
            int y = node.second;
            if(x == desx && y == desy)
            {
                return dist;
            }
            pq.pop();
            for(auto& dir: directions)
            {
                int newX = x+dir[0], newY = y+dir[1];
                int wt = 1;
                if(isSafe(newX, newY) && grid[newX][newY] && dist+wt < result[newX][newY])
                {
                    pq.push({dist+wt, {newX, newY}});
                    result[newX][newY] = dist+wt;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
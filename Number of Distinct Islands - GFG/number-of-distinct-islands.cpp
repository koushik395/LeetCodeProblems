//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int &rows,int &cols,int x,int y,int bx,int by,
    vector<vector<int>>& grid,vector<pair<int,int>> &cor)
    {
        cor.push_back({bx-x,by-y});
        auto isSafe = [&](int& x,int &y)
        {
            return (x >=0 && x < rows && y>=0 && y < cols && grid[x][y]!=0);
        };
        
        for(auto& dir: directions)
        {
            int newX = x+dir[0];
            int newY = y+dir[1];
            if(isSafe(newX, newY))
            {
                grid[newX][newY] = 0;
                dfs(rows,cols,newX,newY,bx,by,grid,cor);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> st;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<pair<int,int>> cor;
                    dfs(rows,cols,i,j,i,j,grid,cor);
                    st.insert(cor);
                }
            }
        }
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
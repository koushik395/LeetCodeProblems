//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int &rows,int &cols,int x,int y,int &newcolor,int &startcolor,vector<vector<int>>& grid)
    {
        grid[x][y] = newcolor;
        auto isSafe = [&](int& x,int &y)
        {
            return (x >=0 && x < rows && y>=0 && y < cols && grid[x][y] == startcolor);
        };
        
        for(auto& dir: directions)
        {
            int newX = x+dir[0];
            int newY = y+dir[1];
            if(isSafe(newX, newY))
            {
                dfs(rows,cols,newX,newY,newcolor,startcolor,grid);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startcol = grid[sr][sc];
        if(startcol == newColor)
            return grid;
        dfs(rows,cols,sr,sc,newColor,startcol,grid);
        
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
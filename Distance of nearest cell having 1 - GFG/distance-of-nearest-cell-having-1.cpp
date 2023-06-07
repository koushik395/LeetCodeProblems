//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
    
        queue < pair < pair < int, int > , int >> q;

        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
    
            if (grid[i][j] == 1) {
              q.push({{i, j}, 0}); 
              
            }
          }
        }
        
        auto isSafe = [&](int& nrow,int &ncol)
        {
              return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0);
        };
    
    
        while (!q.empty()) {
          int r = q.front().first.first;
          int c = q.front().first.second;
          int t = q.front().second;
          
          res[r][c] = t;
          q.pop();
          
          for(auto& dir: directions) {
    
            int nrow = r + dir[0];
            int ncol = c + dir[1];
    
            if (isSafe(nrow,ncol)) {
    
               q.push({{nrow, ncol}, t + 1}); 
    
              grid[nrow][ncol] = 1;
            }
          }
        }
    
    
        return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
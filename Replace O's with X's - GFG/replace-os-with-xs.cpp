//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int i,int j,int rows,int cols)
    { 
        if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j]=='O' && visited[i][j] == 0)
        {
            visited[i][j] = 1;
            dfs(grid,visited,i-1,j,rows,cols);
            dfs(grid,visited,i+1,j,rows,cols);
            dfs(grid,visited,i,j+1,rows,cols);
            dfs(grid,visited,i,j-1,rows,cols);   
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i< n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 'O')
                    if(i==0 || i == n-1 || j==0 || j == m-1)
                    {
                        dfs(grid,visited,i,j,n,m);   
                    }
            }
        }
        
        for(int i = 0;i< n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='O')
                {
                    grid[i][j] = 'X';
                }
            }
        }
        
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
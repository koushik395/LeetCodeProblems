//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        if(n == 1) return matrix[0];
        vector<int> ans;
        if(m == 1)
        {
            for(int i = 0;i < n;i++)
            {
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
        
        int startrow = 0;
        int startcol = 0;
        int endrow = n-1;
        int endcol = m-1;
        for(int index = startcol;index <= endcol;index++)
        {
            ans.push_back(matrix[startrow][index]);
        }
        startrow++;
        for(int index = startrow;index <= endrow; index++)
        {
            ans.push_back(matrix[index][endcol]);
        }
        endcol--;
        for(int index = endcol;index >= startcol; index--)
        {
            ans.push_back(matrix[endrow][index]);
        }
        endrow--;
        for(int index = endrow;index >= startrow; index--)
        {
            ans.push_back(matrix[index][startcol]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
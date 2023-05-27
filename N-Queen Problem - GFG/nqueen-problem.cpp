//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void addsolution(vector<vector<int>> &board,vector<vector<int>> &ans)
{
    vector<int> temp;
    int n = board.size();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(board[j][i] == 1)
            {
                temp.push_back(j+1);
            }
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n,int rowMask,int diag1Mask,int diag2Mask)
{
    //check for same row
    if(rowMask & (1 << row)) return false;
    
    //check for diagnol
    if(diag1Mask & (1 << (row + col))) return false;
    
    if(diag2Mask & (1 << (row - col + n - 1))) return false;
    
    return true;
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n,int rowMask,int diag1Mask,int diag2Mask)
{
    if(col == n)
    {
        addsolution(board,ans);
        return;
    }
    
    for(int row = 0; row < n;row++)
    {
        if(isSafe(row,col,board,n,rowMask,diag1Mask,diag2Mask))
        {
            board[row][col] = 1;
            rowMask |= (1 << row);
            diag1Mask |= (1 << (row + col));
            diag2Mask |= (1 << (row - col + n - 1));
            
            solve(col+1,ans,board,n,rowMask,diag1Mask,diag2Mask);
            
            board[row][col] = 0;
            rowMask &= ~(1 << row);
            diag1Mask &= ~(1 << (row + col));
            diag2Mask &= ~(1 << (row - col + n - 1));
        }
    }
}


class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        
        solve(0,ans,board,n,0,0,0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
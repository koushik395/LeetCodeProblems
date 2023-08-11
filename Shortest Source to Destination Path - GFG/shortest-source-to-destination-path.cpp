//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> direc = {{-1,0},{1,0},{0,1},{0,-1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0) return -1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}}); //steps,x,y
        
        
        auto isSafe = [&](int &x,int &y)
        {
            return (x >=0  && y >=0 && x < N && y < M && A[x][y] == 1);
        };
        
        int mini = 1e9;
        while(!q.empty())
        {
            auto top = q.front();
            int x = top.second.first;
            int y = top.second.second;
            int steps = top.first;
            q.pop();

            if(x == X && y == Y)
            {
                mini = min(mini,steps);
                continue;
            }
            
            for(auto& dir:direc)
            {
                int newx = x + dir[0];
                int newy = y + dir[1];
                if(isSafe(newx,newy))
                {
                    q.push({steps + 1,{newx,newy}});
                    A[newx][newy] = 0;
                }
            }
        }
        
        return (mini == 1e9) ? -1 : mini;;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
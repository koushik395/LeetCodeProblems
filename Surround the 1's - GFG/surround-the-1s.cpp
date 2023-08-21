//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> direc = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int Count(vector<vector<int>>& matrix) {
        int ans = 0;

        int n = matrix.size();
        int m = matrix[0].size();

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 0);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    int count = 0;
                    for (auto& dir : direc) {
                        int newx = i + dir[0];
                        int newy = j + dir[1];
                        if (isSafe(newx, newy)) {
                            count++;
                        }
                    }
                    if (count > 0 && count % 2 == 0) ans++;
                }
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
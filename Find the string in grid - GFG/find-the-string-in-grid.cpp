//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n,m;
    bool isSafe(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool find(vector<vector<char>>& grid, int x, int y, string& word, int idx) {
        if(grid[x][y] != word[0]) return false;
        
        int len = word.size();
        
        for(int i = 0;i < 8;i++)
        {
            int k,rd = x + dx[i],ry = y + dy[i];
            
            for(k = 1;k < len;k++)
            {
                if(!isSafe(rd,ry)) break;
                
                if(grid[rd][ry] != word[k]) break;
                
                rd += dx[i],ry += dy[i];
            }
            
            if(k == len) return true;
        }
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    n = grid.size();
        m = grid[0].size();
    
        vector<vector<int>> result;
    
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                bool found = find(grid, x, y, word, 0);
                if (found) {
                    result.push_back({x,y});
                }
            }
        }
    
        return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
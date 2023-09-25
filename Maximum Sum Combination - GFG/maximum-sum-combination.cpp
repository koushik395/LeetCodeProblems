//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,pair<int,int>> p;
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        
        priority_queue<p> maxh;
        vector<int> ans;
        
        for(int i = 0;i < N;i++)
        {
            maxh.push({A[i]+B[0],{i,0}});
        }
        
        while(!maxh.empty() && K--)
        {
            int topF = maxh.top().second.first;
            int topS = maxh.top().second.second;
            int sum = maxh.top().first;
            maxh.pop();
            
            ans.push_back(sum);
            
            if(topS+1 < B.size())
            {
                maxh.push({A[topF]+B[topS+1],{topF,topS+1}});   
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;

        for(int i = 0;i < N;i++)
        {
            int wt = asteroids[i];
            if(wt < 0)
            {
                while(!st.empty() && st.top() > 0 && st.top() < abs(wt))
                {
                    st.pop();
                }
                if(!st.empty() and st.top() == abs(wt)) {
                    st.pop();
                }
                else{
                    if(st.empty() || st.top() < 0) {
                        st.push(wt);
                    }
                }
            }
            else{
                st.push(wt);
            }
        }
    
        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> st;
        
        int maxi = -1,cnt = 0;
        for(int i = 0,j = 0;j < s.size();j++)
        {
            st[s[j]]++;
            cnt++;
            
            while(st.size() > k)
            {
                cnt--;
                st[s[i]]--;
                if(st[s[i]] == 0) st.erase(s[i]);
                i++;
            }

            if(st.size() == k) maxi = max(maxi,cnt);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
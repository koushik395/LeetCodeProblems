//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    vector<int> charCounts(26, 0);
            queue<char> nonRepeatingChars;
            string result; 
            
            for (char c : a) {
                charCounts[c-'a']++;
                
                if (charCounts[c-'a'] == 1) { 
                    nonRepeatingChars.push(c); 
                }
                
                
                while (!nonRepeatingChars.empty() && charCounts[nonRepeatingChars.front()-'a'] > 1) {
                    nonRepeatingChars.pop();
                }
                
                if (nonRepeatingChars.empty()) { 
                    result.push_back('#');
                } else { 
                    result.push_back(nonRepeatingChars.front());
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
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<long long> curr(2,0),next(2,0);
        next[0] = next[1] = 0;

        for(int ind = n-1;ind >= 0;ind--)
        {
            for(int buy = 0;buy <= 1;buy++)
            {
                long long profit = 0;
                if(buy)
                {
                    profit = max(-prices[ind] + next[0] , 0 + next[1]);
                }
                else
                {
                    profit = max(prices[ind] - fee + next[1], 0 + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
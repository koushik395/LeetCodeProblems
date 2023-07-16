//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(int i,int j,string &text, string &pattern,vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return true; //strings matched
        if(i < 0 && j >= 0) return false; //pattern over but text is there
        if(i >=0 && j < 0)
        {
            for(int k = 0;k <= i;k++) if(pattern[k] != '*') return false;
            return true;
            //'*' can match empty
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == text[j] || pattern[i] == '?')
        {
            return dp[i][j] = f(i-1,j-1,text,pattern,dp);
        }
        
        if(pattern[i] == '*') //matches empty or character
        {
            return dp[i][j] = f(i,j-1,text,pattern,dp) || f(i-1,j,text,pattern,dp);
        }
        
        return dp[i][j] = false;
        
    }
    int wildCard(string pattern,string text)
    {
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends
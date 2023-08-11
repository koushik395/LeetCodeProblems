//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string &s,int index,vector<string> &res)
    {
        if(index >= s.size())
        {
            res.push_back(s);
            return;
        }
        for(int j=index;j<s.size();j++)
        {
            swap(s[index],s[j]);
            solve(s,index+1,res);
            swap(s[index],s[j]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> res;
        
        solve(S,0,res);
        
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
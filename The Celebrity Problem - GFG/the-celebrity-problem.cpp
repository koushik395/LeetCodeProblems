//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    void find(vector<vector<int> >& M, int n,stack<int> &st)
    {
        while(st.size()!=1)
        {
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            st.pop();
            if(M[p1][p2]!= 1)
                st.push(p1);
            else
                st.push(p2);
        }
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        find(M,n,st);
        int person = st.top();
        int col=0,row= 0;
        for(int i= 0;i<n;i++)
        {
            if(M[person][i] == 0)
                row++;
        }
        for(int i= 0;i<n;i++)
        {
            if((M[i][person] == 1) && i!=person)
                col++;
        }
        return (row==n)&&(col==n-1)?person:-1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
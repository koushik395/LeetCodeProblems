//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void calculate(vector<int> &indegree,vector<int> adj[],int child)
	{
	    for(auto& neighbour:adj[child])
	    {
	        indegree[neighbour]++;
	    }
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> indegree(v,0);
	    
	    for(int i=0;i<v;i++)
	    {
	        calculate(indegree,adj,i);
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    while(q.size()!=0)
	    {
	        int front = q.front();
	        ans.push_back(front);
	        q.pop();
	        for(auto& neighbour:adj[front])
	        {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
	        }
	    }
	   return ans;
	}
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr = 0;ptr < len;ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K,adj);
        
        string ans = "";
        for(auto& it:topo)
        {
            ans.push_back(char(it+'a'));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
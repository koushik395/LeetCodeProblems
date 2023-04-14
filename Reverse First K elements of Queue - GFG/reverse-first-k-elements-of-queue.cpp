//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
void reverseKelements(queue<int> &q, int k,int index)
{
       if(index == k)
          return;
        
        int val = q.front();
        q.pop();
        
        reverseKelements(q,k,index+1);
        
        q.push(val);
}
queue<int> modifyQueue(queue<int> q, int k) {
    reverseKelements(q,k,0);
    
    for(int i =0;i < (q.size()-k);i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}
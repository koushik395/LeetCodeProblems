//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

int mini;
void push(stack<int>& s, int data){
	 if(s.empty()) {
            s.push(data);
            mini = data;
    }
    else
    {
     	if(data < mini) {
            s.push(2*data - mini);
            mini = data;
        }   
        else
        {
            s.push(data);
        }
    }
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n)
	    return true;
	return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	if(s.empty()){
        return -1;
    }
    
    int curr = s.top();
    s.pop();
    if(curr > mini) {
        return curr;
    }
    else
    {
        int prevMin = mini;
        int val = 2*mini - curr;
        mini = val;
        return prevMin;
    }
}

int getMin(stack<int>& s){
	if(s.empty())
        return -1;
        
    return mini;
}
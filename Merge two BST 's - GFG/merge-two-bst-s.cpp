//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //step1 convert into sorted DLL
    void ConvertIntosortedDLL(Node* root,Node* &head)
    {
        if(root==NULL) return;
        
        ConvertIntosortedDLL(root->right,head);
        
        root->right = head;
        
        if(head!=NULL)
            head->left = root;
        head = root;
        
        ConvertIntosortedDLL(root->left,head);
    }
    
    Node* mergeTwoLists(Node* head1, Node* head2) {
        Node* head = NULL;
        Node* tail = NULL;
        
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->data < head2->data)
            {
                if(head == NULL)
                {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else
                {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            }
            else
            {
                if(head == NULL)
                {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else
                {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }
        if(head1)
            tail->right = head1;
        if(head2)
            tail->right = head2;
        return head;
		
	}
	
    vector<int> merge(Node *root1, Node *root2)
    {
        Node* head1 = NULL;
        ConvertIntosortedDLL(root1,head1);
        head1->left = NULL;
        
        Node* head2 = NULL;
        ConvertIntosortedDLL(root2,head2);
        head2->left = NULL;
        
        Node* head = mergeTwoLists(head1,head2);
        
        vector<int> ans;
        while(head!=NULL)
        {
            ans.push_back(head->data);
            head = head->right;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends
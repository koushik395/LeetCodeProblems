class node{
  public:
    int data;
    int row;
    int col;
    node(int data,int row,int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
       bool operator()(node* a,node* b)
       {
           return a->data > b->data;
       }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<node*,vector<node*>, compare> minheap;
        
        for(int i = 0;i< k;i++)
        {
            int ele = nums[i][0];
            minheap.push(new node(ele,i,0));
            maxi = max(maxi,ele) ;
            mini = min(mini,ele);
        }
        
        int start = mini,end = maxi;
        
        while(!minheap.empty())
        {
            node* temp = minheap.top();
            minheap.pop();
            mini = temp->data;
            
            if(maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
            
            int n = nums[temp->row].size();
            if(temp->col + 1< n)
            {
                maxi = max(maxi , nums[temp->row][temp->col+1]);
                minheap.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col + 1));
            }else break;
        }
        return {start,end};
    }
};
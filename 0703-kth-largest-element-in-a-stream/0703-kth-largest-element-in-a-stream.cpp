class KthLargest {
public:
    int kth;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        int n = nums.size();
        for(auto& num:nums)
        {
            minheap.push(num);
            if(minheap.size() > kth)
                minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > kth)
            minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
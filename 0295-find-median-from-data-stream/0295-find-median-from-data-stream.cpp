class MedianFinder {
public:
    double median;
    vector<int> nums;
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>,greater<double>> minheap;
    int i;
    
    int signum(int a,int b)
    {
        if(a==b) return 0;
        return a > b? 1: -1;
    }
    
    void callMedian(int &element,priority_queue<double> &maxheap,priority_queue<double, vector<double>,greater<double>> &minheap,double &median)
    {
        switch(signum(maxheap.size(),minheap.size()))
        {
            case 0: if(element > median){
                        minheap.push(element);
                        median = minheap.top();
                    }
                    else{
                        maxheap.push(element);
                        median = maxheap.top();
                    }
                    break;
            case 1:
                    if(element > median){
                        minheap.push(element);
                        median = (maxheap.top()+minheap.top())/2;
                    }
                    else{
                        minheap.push(maxheap.top());
                        maxheap.pop();
                        maxheap.push(element);
                        median = (maxheap.top()+minheap.top())/2;
                    }
                    break;
            case -1:
                    if(element > median){
                        maxheap.push(minheap.top());
                        minheap.pop();
                        minheap.push(element);
                        median = (maxheap.top()+minheap.top())/2;
                    }
                    else{
                        maxheap.push(element);
                        median = (maxheap.top()+minheap.top())/2;
                    }
                    break;
         }
    }
    MedianFinder() {
        median = 0;
        i = -1;
    }
    
    void addNum(int num) {
        i++;
        nums.push_back(num);
    }
    
    double findMedian() {
        if(!maxheap.size() && !minheap.size())
        {
            for(auto& num:nums)
            {
                callMedian(num,maxheap,minheap,median);
            }
        }
        else
        {
            for(int j = i;j < nums.size();j++)
            {
                callMedian(nums[j],maxheap,minheap,median);   
            }   
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
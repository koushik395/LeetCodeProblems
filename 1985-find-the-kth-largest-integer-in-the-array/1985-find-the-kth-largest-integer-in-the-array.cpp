class Solution {
public:
    bool operator() (string &b, string &a) { 
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
    string kthLargestNumber(vector<string>& arr, int k) {
        priority_queue<string, vector<string>, Solution> minHeap;
        for (string& num : arr) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        
        for(int i = 0;i < gifts.size();i++)
        {
            pq.push(gifts[i]);
        }
        
        while(k--)
        {
            int top = pq.top();
            pq.pop();
            int rt = sqrt(top);
            pq.push(rt);
        }
        
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
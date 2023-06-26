class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> m1,m2;
        
        int n = costs.size(),i = 0,j = n-1;
        long long sum  = 0;
        while(k--)
        {
            while(m1.size()<candidates && i<=j) m1.push(costs[i++]);
            while(m2.size()<candidates && j>=i) m2.push(costs[j--]);
            
            int num1 = m1.size()>0? m1.top():INT_MAX;
            int num2 = m2.size()>0? m2.top():INT_MAX;
            
            if(num1 <= num2)
            {
                sum += num1;
                m1.pop();
            }
            else
            {
                sum += num2;
                m2.pop();
            }
        }
        
        return sum;
    }
};
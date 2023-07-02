class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i < reward1.size();i++)
        {
            pq.push({reward1[i] - reward2[i],i});
        }
        
        int score = 0;
        while(k > 0)
        {
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            score += reward1[b];
            k--;
        }
        while(pq.size())
        {
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            score += reward2[b];
        }
        return score;
    }
};
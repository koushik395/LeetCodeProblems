class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n,0);
        int maxi = -1,node = 0;
        for(int i = 0;i < n;i++)
        {
            scores[edges[i]] += i;
        }
        for (int i = 0; i < n; i++) {
            if (scores[i] > scores[node]) {
                node = i;
            }
        }
        return node;
    }
};
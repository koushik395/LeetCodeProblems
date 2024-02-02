class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i <= 8; i++) {
            q.push(i);
        }
        vector<int> ret;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(f <= high && f >= low) {
                ret.push_back(f);
            }
            if(f > high)
                break;
            int num = f % 10;
            if(num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};
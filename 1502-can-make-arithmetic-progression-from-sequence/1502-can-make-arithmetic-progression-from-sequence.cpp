class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_map<int,bool> mp;
        int maxi = INT_MIN, mini = INT_MAX, n = 0;
        for(auto& num:arr)
        {
            ++n;
            mp[num] = true;
            if(num < mini) mini = num;
            if(num > maxi) maxi = num;
        }
        if(mini == maxi)return true;
        
        int diff = ceil((maxi - mini)*1.0/(n-1));
        for(int i = 0;i < n;i++)
        {
            int num = mini + i * diff;
            if(!mp[num]) return false;
        }
        return true;
    }
};
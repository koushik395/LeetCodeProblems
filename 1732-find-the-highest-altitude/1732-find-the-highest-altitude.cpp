class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxi = INT_MIN;
        for(auto& num: gain)
        {
            sum += num;
            if(sum > maxi)
            {
                maxi = sum;
            }
        }
        return maxi > 0 ? maxi : 0;
    }
};
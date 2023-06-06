class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int maxi = INT_MIN, mini = INT_MAX, n = 0;
        for(auto& num:arr)
        {
            ++n;
            if(num < mini) mini = num;
            if(num > maxi) maxi = num;
        }
        if(mini == maxi)return true;
        
        int diff = ceil((maxi - mini)*1.0/(n-1));
        int i = 0;
        while(i < n)
        {
            if(arr[i] == mini+i*diff) i++;//correct pos;
            else if((arr[i]-mini)%diff !=0) return false;
            else
            {
                int pos = (arr[i] - mini)/diff;
                if(pos < i || arr[pos] == arr[i]) return false;//infinite loop
                swap(arr[pos],arr[i]);
            }
        }
        return true;
    }
};
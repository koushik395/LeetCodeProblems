class Solution {
public:
    bool isPossible(int &EmpLft,int &EmpRig,long long &totalSum,int &ele,int &mid,int &max)
    {
        totalSum = mid;
        if(EmpRig <= ele) // right part
        {
            totalSum += (ele*1LL*(ele+1))/2 - ((ele - EmpRig)*1LL*((ele - EmpRig) + 1))/2;
        }
        else
        {
            totalSum += (ele*1LL*(ele+1))/2 + (EmpRig - ele);
        }
        
        if(EmpLft <= ele) // left part
        {
            totalSum += (ele*1LL*(ele+1))/2 - ((ele - EmpLft)*1LL*((ele - EmpLft) + 1))/2;
        }
        else
        {
            totalSum += (ele*1LL*(ele+1))/2 + (EmpLft - ele);
        }
        
        if(totalSum <= max) return true;
        return false;
    }
    int maxValue(int n, int index, int maxSum) {
        int EmptyLeft = index;
        int EmptyRight = n - index - 1;
        
        int low = 1,high = maxSum;
        int res;
        while(low <= high)
        {
            int mid = low + (high - low)/2,elements = mid-1;
            long long totalSum = 0;
            
            if(isPossible(EmptyLeft,EmptyRight,totalSum,elements,mid,maxSum))
            {
                low = mid+1;
                res = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }
};
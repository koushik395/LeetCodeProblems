class Solution {
public:
    bool isPossible(int mid,int m,int k,vector<int>& arr)
    {
        int cnt = 0,totalBouquet = 0;
        
        for(int i = 0;i < arr.size();i++)
        {
            if(arr[i] <= mid)
            {
                cnt++;
            }
            else
            {
                totalBouquet += cnt/k;
                cnt = 0;
            }
        }
        totalBouquet += cnt/k;
        return totalBouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*1LL*k > n) return -1;
        
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(mid,m,k,bloomDay))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};
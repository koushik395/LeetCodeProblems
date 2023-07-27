class Solution {
public:
    bool isPossible(vector<int>& batteries,long long time,long long comp)
    {
        long long totalTime = 0,cnt = 0;
        
        for(auto& btime:batteries)
        {
            if(btime < time) totalTime += btime,cnt++;
            // else totalTime += time;
        }
        
        int numComp = comp - (batteries.size()-cnt);
        return (totalTime >= time * numComp);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1,high;
        for(auto& btime: batteries)
        {
            high += btime;
        }
        
        long long ans = 1;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            if(isPossible(batteries,mid,n))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
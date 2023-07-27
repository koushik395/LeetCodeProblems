class Solution {
public:
    long long numBatt;
    bool isPossible(vector<int>& batteries,long long time,long long comp)
    {
        long long totalTime = 0,lessBatt = 0;
        
        for(auto& btime:batteries)
        {
            if(btime < time)
            {
                totalTime += btime;
                lessBatt++;  
            } 
        }
        
        int numComp = comp - (numBatt-lessBatt); // number of remaining computers
        return (totalTime >= time * numComp);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1,high;
        numBatt = batteries.size();
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
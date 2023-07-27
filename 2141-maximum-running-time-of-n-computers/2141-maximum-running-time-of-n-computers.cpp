class Solution {
public:
    /* count the number of (batteries_charge > time) since they can charge the 
           computers for the period of the required time.
           Now find out how many computers are left out and the total batteries charge we have.
           If(Total_charge/number_of_computers_left_out >=  required_time) then we charge the 
           remaining computers with remaining batteries charge.*/
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
        
        int numCompLeft = comp - (numBatt-lessBatt);
        return (totalTime >= time * numCompLeft);
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
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[1] < b[1]) return true;
        else if(a[1] == b[1]) return a[0] < b[0];
        return false;
    }
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int maxiDay = events[events.size()-1][1];
        int cnt = 0;
        set<int> days;
        for(int i = 1;i <= maxiDay;i++)
        {
            days.insert(i);
        }
        for(auto& eve:events)
        {
            int s = eve[0];
            int e = eve[1];
            auto it = days.lower_bound(s);
            if(it == days.end() || *it > e)
            {
                continue;
            }
            else
            {
                cnt++;
                days.erase(it);
            }
        }
        return cnt;
    }
};
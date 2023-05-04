class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiants,dire;
        int n = senate.length();
        for(int i = 0;i < n;i++)
        {
            if(senate[i]=='R') radiants.push(i);
            else dire.push(i);
        }
        
        while(!radiants.empty() && !dire.empty())
        {
            int rad_ind = radiants.front(),dir_ind = dire.front();
            radiants.pop(),dire.pop();
            (rad_ind < dir_ind) ? radiants.push(rad_ind+n):dire.push(dir_ind+n);
        }
        return (!radiants.empty()) ? "Radiant":"Dire";
    }
};
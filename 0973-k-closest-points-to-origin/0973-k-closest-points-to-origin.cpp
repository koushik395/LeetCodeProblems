class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ans;
        auto dist = [&](int &x1,int &y1)
        {
            return pow((x1),2)+pow((y1),2);
        };
        
        for(int i = 0 ;i < k;i++)
        {
            int distance = dist(points[i][0],points[i][1]); 
            pq.push({distance,{points[i][0],points[i][1]}});
        }
        
        for(int i = k;i < points.size();i++)
        {
            int distance = dist(points[i][0],points[i][1]); 
            if(pq.top().first > distance)
            {
                pq.pop();
                pq.push({distance,{points[i][0],points[i][1]}});
            }
        }
        while(!pq.empty())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
                        
        return ans;
    }
};
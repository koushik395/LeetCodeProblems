class Solution {
public:
    bool connected(int v,int sv,vector<vector<int>> &adj,vector<bool> &visited)
    {
        if (v==0)
            return true;
        int count =0;
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while(q.size() > 0)
        {
            int front = q.front();
            q.pop();
            count++;
            for(auto& neighbour:adj[front])
            {
                if(visited[neighbour]!=true)
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        if(count == v)
            return true;
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        return connected(n,0,rooms,visited);
    }
};
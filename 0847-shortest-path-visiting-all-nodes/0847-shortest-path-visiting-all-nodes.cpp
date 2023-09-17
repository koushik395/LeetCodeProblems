class Node{
    public:
    int node;
    int mask;
    int length;

    Node(int node,int mask,int length)
    {
        this->node = node;
        this->mask = mask;
        this->length = length;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        queue<Node> q;
        set<pair<int,int>> vis;
        int allNodes = (1 << n) - 1;
        
        for(int i = 0;i < n;i++)
        {
            int mask = (1 << i);
            Node node(i,mask,1);
            q.push(node);
            
            vis.insert({i,mask});
        }
        
        while(!q.empty())
        {
            Node curr = q.front();
            q.pop();
            
            if(curr.mask == allNodes)
            {
                return curr.length - 1;
            }
            
            for(auto& adj: graph[curr.node])
            {
                int adjMask = curr.mask;
                
                adjMask = adjMask | (1 << adj);
                
                Node node(adj,adjMask,curr.length + 1);
                
                if(vis.find({adj,adjMask}) == vis.end())
                {
                    vis.insert({adj,adjMask});
                    q.push(node);
                }
            }
        }
        return -1;
    }
};
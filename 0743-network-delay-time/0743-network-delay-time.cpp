class Solution {
public:
    struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int source = time[0];
            int target = time[1];
            int weight = time[2];
            graph[source].push_back({target, weight});
        }

        // Array to store the minimum distance from source to each node
        vector<int> dist(n + 1, INT_MAX);

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        // Start with the source node
        dist[k] = 0;
        pq.push({k, 0});

        while (!pq.empty()) {
            int node = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();

            // If the current distance is greater than the stored distance, skip
            if (currDist > dist[node])
                continue;

            // Iterate through the neighbors of the current node
            for (const auto& neighbor : graph[node]) {
                int neighborNode = neighbor.first;
                int neighborDist = neighbor.second;

                // Calculate the new distance to the neighbor node
                int newDist = currDist + neighborDist;

                // If the new distance is smaller, update the minimum distance and add to the priority queue
                if (newDist < dist[neighborNode]) {
                    dist[neighborNode] = newDist;
                    pq.push({neighborNode, newDist});
                }
            }
        }

        // Find the maximum distance from the source node
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1; // There is a node that cannot receive the signal
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
        }
};
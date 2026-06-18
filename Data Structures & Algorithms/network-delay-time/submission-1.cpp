class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         // node, dist
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

    // Dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int>distance(n+1, INT_MAX);
        distance[k] = 0;

        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            int dist = top.first, node = top.second;
            for(pair<int, int> neigh: adj[node]){
                int dist2 = dist + neigh.second;
                if(distance[neigh.first] > dist2){
                    pq.push({dist2, neigh.first});
                    distance[neigh.first] = dist2;
                }
            }
        }
        int maxDist = -1;
        for(int i=1; i<=n; i++){
            if(distance[i] == INT_MAX){
                return -1;
            }
            maxDist = max(maxDist, distance[i]);
        }
        return maxDist;
    }
};

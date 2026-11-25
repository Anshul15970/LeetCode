class Solution {
public:

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        vector<int> dist(n,0);
        vector<int> rec(n,0);
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(vis[i]){continue;}
            int node = i;
            int d = 0;
            while(node != -1 && !vis[node]){
                vis[node] = 1;
                rec[node] = 1;
                dist[node] = d++;
                node = edges[node];
            }
            if(node != -1 && rec[node]){
                ans = max(ans,d - dist[node]);
            }
            node = i;
            while(node != -1 && rec[node]){rec[node] = 0; node = edges[node];}
        }
        return ans;
    }
};
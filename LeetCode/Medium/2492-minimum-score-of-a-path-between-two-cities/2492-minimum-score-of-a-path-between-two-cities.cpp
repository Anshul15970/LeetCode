class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    void dfs(int i,int &minval,vector<int> &vis){
        vis[i] = 1;
        for(auto [neighbour,val] : adj[i]){
            minval = min(minval,val);
            if(!vis[neighbour]){
                dfs(neighbour,minval,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto &i : roads){
            int u = i[0], v = i[1], val = i[2];
            adj[u].push_back({v,val});
            adj[v].push_back({u,val});
        }
        int minval = INT_MAX;
        vector<int> vis(n+1,0);
        dfs(1,minval,vis);
        return minval;
    }
};
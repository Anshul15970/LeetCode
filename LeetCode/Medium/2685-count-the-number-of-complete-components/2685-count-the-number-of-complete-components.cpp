class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(int i,int &v,int &e,vector<int>& vis){
        vis[i] = 1;
        v++;
        e += adj[i].size();
        for(auto ne : adj[i]){if(!vis[ne]){dfs(ne,v,e,vis);}}
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        for(auto i : edges){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int v = 0,e = 0;
            if(!vis[i]){
            dfs(i,v,e,vis);
            if(e/2 == (v*(v-1))/2){ans++;}}
        }
        return ans;
    }
};
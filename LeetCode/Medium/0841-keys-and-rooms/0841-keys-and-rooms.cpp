class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int viscount = 0;
    void dfs(int i,vector<int> &vis){
        vis[i] = 1;
        viscount++;
        for(auto node : adj[i]){
            if(!vis[node]){dfs(node,vis);}
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        for(int i = 0;i<n;i++){
            adj[i] = rooms[i];
        }
        vector<int> vis(n,0);
        dfs(0,vis);
        if(viscount == n){return true;}
        return false;
    }
};
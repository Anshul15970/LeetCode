class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(int i,vector<int> &vis){
        vis[i] = 1;
        for(auto node : adj[i]){
            if(!vis[node]){dfs(node,vis);}
        }
    }
    int findCircleNum(vector<vector<int>>& C) {
        int n = C.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(C[i][j] == 1){
                adj[i].push_back(j);}
            }
        }
        int ans = 0;
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
            dfs(i,vis);
            ans++;}
        }
        return ans;
    }
};
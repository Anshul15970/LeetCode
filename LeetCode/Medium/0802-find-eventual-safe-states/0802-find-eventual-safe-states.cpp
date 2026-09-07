class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool dfs(int i,vector<int> &vis,vector<int> &cycle){
        cycle[i] = true;
        vis[i] = true;
        for(auto &node : adj[i]){
            if(!vis[node] && dfs(node,vis,cycle)){return true;}
            else if(cycle[node]){return true;}
        }
        cycle[i] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0;i<n;i++){
            adj[i]=graph[i];
        }
        vector<int> ans;
        vector<int> vis(n,0),cycle(n,0);
        for(int i = 0;i<n;i++){
            if(!dfs(i,vis,cycle)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
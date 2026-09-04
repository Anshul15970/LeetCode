class Solution {
public:
    int ans = 0;
    unordered_map<int,vector<pair<int,int>>> map;
    int dfs(int node,int parent){
        int ans = 0;
        for(auto [neighbour, cost] : map[node]){
            if(neighbour == parent){continue;}
            ans += cost;
            ans += dfs(neighbour, node);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto i : connections){
            int u = i[0], v = i[1];
            map[u].push_back({v,1});
            map[v].push_back({u,0});
        }
        return dfs(0,-1);
    }
};
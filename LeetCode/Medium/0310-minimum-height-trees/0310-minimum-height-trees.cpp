class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){return {0};}
        unordered_map<int,vector<int>> adj;
        for(auto &i : edges){
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);}
        vector<int> degree(n,0);
        queue<int> q;
        for(int i = 0;i<n;i++){
            degree[i] = adj[i].size();
            if(degree[i] == 1){q.push(i);}}
        int rem = n;
        while(rem > 2){
            int size = q.size();
            rem -= size;
        while(size--){
            int node = q.front();  q.pop();
            for(auto &i : adj[node]){
                degree[i]--;
                if(degree[i] == 1){q.push(i);}
            }
        }}
        vector<int> ans;
        while(q.size()){ans.push_back(q.front()); q.pop();}
        return ans;
    }
};
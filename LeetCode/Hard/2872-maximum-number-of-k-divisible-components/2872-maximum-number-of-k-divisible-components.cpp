class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> ans;
    int cnt = 0;
    long long dfs(int parent,int node,int k){
        long long val = ans[node];
        for(auto &i : adj[node]){
            if(i == parent){continue;}
            val += dfs(node,i,k);
        }
        if(val%k == 0){cnt++; return 0;}
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ans.resize(n);
        ans = values;
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(-1,0,k);
        return cnt;
    }
};
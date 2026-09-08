class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){return 0;}
        unordered_map<int, vector<int>> adj;
        int n = routes.size(), bus = -1;
        for(int i = 0;i<n;i++){
            for(auto j : routes[i]){
                adj[j].push_back(i);}}
        queue<vector<int>> q;
        q.push({source,0});
        vector<int> vis1(n,0);
        unordered_map<int,int> vis2;
        while(q.size()){
            int node = q.front()[0], val = q.front()[1]; q.pop();
            vis2[node] = 1;
            for(auto j : adj[node]){
                if(!vis1[j]){
                    for(auto k : routes[j]){
                    if(!vis2[k]){q.push({k,val+1});}
                    if(k == target){return val+1;}}
                    vis1[j] = 1;}
            }
        }
        return -1;
    }
};
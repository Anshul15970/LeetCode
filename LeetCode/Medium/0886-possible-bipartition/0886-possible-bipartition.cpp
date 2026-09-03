class Solution {
public:
    unordered_map<int,vector<int>> map;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0;i<dislikes.size();i++){
            int u = dislikes[i][0], v = dislikes[i][1];
            map[u].push_back(v);
            map[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i = 1;i<=n;i++){
        if(color[i] != -1){continue;}
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while(q.size()){
            int node = q.front(); 
            q.pop();
            for(auto neighbour : map[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = 1-color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[node]){return false;}
            }
        }}
        return true;
    }
};
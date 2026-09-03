class Solution {
public:
    unordered_map<int,vector<pair<int,char>>> m; 
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n,-1);
        vector<vector<int>> visited(n,vector<int> (2,0));
        for(auto i : redEdges){
            int u = i[0], v = i[1];
            m[u].push_back({v,'R'});
        }
        for(auto i : blueEdges){
            int u = i[0], v = i[1];
            m[u].push_back({v,'B'});
        }
        queue<pair<int,char>> q;
        q.push({0,'N'});
        ans[0] = 0;
        int r = 0;
        while(q.size()){
            int s = q.size();
            while(s--){
                int node = q.front().first;
                char color = q.front().second;
                q.pop();
                for(auto [neighbour, c] : m[node]){
                    if(color == c){continue;}
                    if(c == 'R'){
                        if(!visited[neighbour][0]){
                            visited[neighbour][0] = 1;
                            q.push({neighbour,c});
                        if(ans[neighbour] == -1){ans[neighbour] = r+1;}
                        }
                    }
                    if(c == 'B'){
                        if(!visited[neighbour][1]){
                            visited[neighbour][1] = 1;
                            q.push({neighbour,c});
                        if(ans[neighbour] == -1){ans[neighbour] = r+1;}
                        }
                    }
                }
            }
                r++;
        }
        return ans;
    }
};
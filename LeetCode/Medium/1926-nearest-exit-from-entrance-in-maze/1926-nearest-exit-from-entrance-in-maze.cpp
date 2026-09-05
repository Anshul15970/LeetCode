class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<vector<int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        q.push({e[0],e[1],0});
        vis[e[0]][e[1]] = 1;
        while(q.size()){
            int i = q.front()[0], j = q.front()[1], val = q.front()[2]; 
            q.pop();
            if(i-1>=0 && maze[i-1][j] == '.' && !vis[i-1][j]){
            if(i-1==0 || j == m-1 || i-1==n-1 || j == 0){return val+1;} q.push({i-1,j,val+1});
             vis[i-1][j]=1;}
            if(i+1<n && maze[i+1][j] == '.' && !vis[i+1][j]){
            if(i+1==n-1 || i+1 == 0 || j == m-1 || j == 0){return val+1;} q.push({i+1,j,val+1}); 
            vis[i+1][j]=1;}
            if(j-1>=0 && maze[i][j-1] == '.' && !vis[i][j-1]){
            if(j-1==0 || j-1 == m-1 || i == 0 || i == n-1){return val+1;} q.push({i,j-1,val+1}); 
            vis[i][j-1]=1;}
            if(j+1<m && maze[i][j+1] == '.' && !vis[i][j+1]){
            if(j+1==m-1 || j+1 == 0 || i==0 || i == n-1){return val+1;} q.push({i,j+1,val+1}); 
            vis[i][j+1]=1;}
        }
        return -1;
    }
};
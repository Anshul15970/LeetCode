class Solution {
public:
    int n,m;
    void dfs(int i, int j , vector<vector<int>>& grid){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] != 1){return;}
        grid[i][j] = 2;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        bool f = false;
        for(int i = 0;i<n && !f;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){dfs(i,j,grid); f = true; break;}
            }
        }
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){q.push({i,j});}
            }
        }
        while(q.size()){
            int s = q.size();
            while(s--){
                int a = q.front().first, b = q.front().second; q.pop();
                if(a-1 >= 0 && grid[a-1][b] == 0){grid[a-1][b] = 2; q.push({a-1,b});}
                else if(a-1 >= 0 && grid[a-1][b] == 1){return ans;}
                if(a+1 < n && grid[a+1][b] == 0){grid[a+1][b] = 2; q.push({a+1,b});}
                else if(a+1 < n && grid[a+1][b] == 1){return ans;}
                if(b-1 >= 0 && grid[a][b-1] == 0){grid[a][b-1] = 2; q.push({a,b-1});}
                else if(b-1 >= 0 && grid[a][b-1] == 1){return ans;}
                if(b+1 < m && grid[a][b+1] == 0){grid[a][b+1] = 2; q.push({a,b+1});}
                else if(b+1 < m && grid[a][b+1] == 1){return ans;}
            }
            ans++;
        }
        return -1;
    }
};
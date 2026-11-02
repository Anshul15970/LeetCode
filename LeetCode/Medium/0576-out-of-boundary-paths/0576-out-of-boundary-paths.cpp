class Solution {
public:
    int MOD = 1e9 + 7;
    long long dfs(int i, int j,int l,int n,int m,vector<vector<vector<int>>> &dp) {
        if(i < 0 || j < 0 || i >= n || j >= m){return 1;}
        if(l == 0){return 0;}
        if(dp[i][j][l] != -1){return dp[i][j][l];}
        long long a = dfs(i-1,j,l-1,n,m,dp);
        long long b = dfs(i+1,j,l-1,n,m,dp);
        long long c = dfs(i,j-1,l-1,n,m,dp);
        long long d = dfs(i,j+1,l-1,n,m,dp);
        return dp[i][j][l] = (a+b+c+d)%MOD;
}

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp (n,vector<vector<int>> (m,vector<int> (maxMove+1,-1)));
        return dfs(startRow,startColumn,maxMove,n,m,dp)%MOD;
    }
};
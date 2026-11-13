class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>& strs,int i,int m,int n){
        if(i >= strs.size()){return 0;}
        if(dp[i][m][n] != -1){return dp[i][m][n];}
        int s1 = 0,s2 = 0;
        for(char &c : strs[i]){if(c == '0'){s1++;} else{s2++;}}
        int take = 0; int skip = 0;
        if(s1 <= m && s2 <= n){
        take = 1 + solve(strs,i+1,m-s1,n-s2);}
        skip = solve(strs,i+1,m,n);
        return dp[i][m][n] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);
    }
};
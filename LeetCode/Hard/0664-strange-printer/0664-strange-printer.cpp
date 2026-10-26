class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l,int r,string s){
        if(l == r){return 1;}
        if(l > r){return 0;}
        if(dp[l][r] != -1){return dp[l][r];}
        int i = l+1;
        while( i <= r && s[i] == s[l]){i++;}
        if(i == r+1){return 1;}
        int a = 1 + solve(i,r,s);
        int b = INT_MAX;
        for(int j = i;j<=r;j++){
            if(s[l] == s[j]){
                int c = solve(i,j-1,s) + solve(j,r,s);
                b = min(c,b);
            }
        }
        return dp[l][r] = min(a,b);
    }
    int strangePrinter(string s) {
        int n = s.length();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
};
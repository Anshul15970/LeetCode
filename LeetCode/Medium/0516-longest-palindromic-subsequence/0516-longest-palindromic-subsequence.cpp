class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int> (n,1));
        int i = 0,j = n-1;
        int ans = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
               if(s[i] == s[j]){dp[i][j] = 2 + (j - i > 1 ? dp[i+1][j-1] : 0);}
                else{dp[i][j] = max(dp[i+1][j],dp[i][j-1]);}
            }
        }
        return dp[0][n-1];
    }
};
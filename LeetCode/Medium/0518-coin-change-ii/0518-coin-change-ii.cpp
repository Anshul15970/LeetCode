class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins,int t,int i){
        if(t == 0){return 1;}
        if(t < 0 || i >= coins.size()){return 0;}
        if(dp[i][t] != -1){return dp[i][t];}
        int take = solve(coins,t-coins[i],i);
        int skip = solve(coins,t,i+1);
        return dp[i][t] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n,vector<int> (amount+1,-1));
        return solve(coins,amount,0);
    }
};
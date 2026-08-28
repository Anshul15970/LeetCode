class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> dp;
    int solve(int i,vector<int>& coins,int amount){
        if(i == coins.size()){return INF;}
        if(amount == 0){return 0;}
        if(dp[i][amount] != -1){return dp[i][amount];}
        if(amount < coins[i]){return solve(i+1,coins,amount);}
        int take = 1 + solve(i,coins,amount-coins[i]);
        int skip = solve(i+1,coins,amount);
        return dp[i][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount);
        return ans==INF?-1:ans;
    }
};
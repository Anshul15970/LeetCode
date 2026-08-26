class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int idx,int prev,int left,vector<int> &rating,bool increasing){
        if(left == 0){return 1;}
        if(idx == rating.size()){return 0;}
        if(dp[idx][prev+1][left] != -1){return dp[idx][prev+1][left];}
        int ans = solve(idx+1,prev,left,rating,increasing);
        if(prev == -1 || (increasing && rating[idx] > rating[prev]) || 
           (!increasing && rating[idx] < rating[prev])){
            ans += solve(idx+1,idx,left-1,rating,increasing);
           }
        return dp[idx][prev+1][left] = ans;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        dp.assign(n,vector<vector<int>>(n+1, vector<int>(4,-1)));
        ans += solve(0,-1,3,rating,true);
        dp.assign(n,vector<vector<int>>(n+1, vector<int>(4,-1)));
        ans += solve(0,-1,3,rating,false);
        return ans;
    }
};
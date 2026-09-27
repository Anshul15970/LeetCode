class Solution {
public:
    unordered_map<string,int> dp;
    int solve(vector<int>& nums, int t,int i,int num){
        if(i >= nums.size()){
            if(t == num){return 1;}
            return 0;}
        string key = to_string(i) + "," + to_string(num);
        if(dp.count(key)){return dp[key];}
        int plus = 0,minus = 0;
        plus += solve(nums,t,i+1,num+nums[i]);
        minus += solve(nums,t,i+1,num-nums[i]);
        return dp[key] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};
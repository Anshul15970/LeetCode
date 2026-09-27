class Solution {
public:
    int solve(vector<int>& nums, int t,int i,int num){
        if(i >= nums.size()){
            if(t == num){return 1;}
            return 0;}
        int plus = 0,minus = 0;
        plus += solve(nums,t,i+1,num+nums[i]);
        minus += solve(nums,t,i+1,num-nums[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};
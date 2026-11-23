class Solution {
public:
    vector<vector<int>> PT;
    long long MOD = 1e9 + 7;
    long long solve(vector<int>& nums){
        int n = nums.size();
        if(n < 3){return 1;}
        int root = nums[0];
        vector<int> larr;
        vector<int> rarr;
        for(int i = 1;i<n;i++){
            if(nums[i] < root){larr.push_back(nums[i]);}
            else{rarr.push_back(nums[i]);}
        }
        long long x = solve(larr)%MOD;
        long long y = solve(rarr)%MOD;
        long long z = PT[n-1][larr.size()];
        return ((x * y)%MOD * z)%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        PT.resize(n+1);
        for(int i = 0;i<=n;i++){
            PT[i] = vector<int>(i+1,1);
            for(int j = 1;j<i;j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%MOD;
            }
        }
        return solve(nums)%MOD-1;
    }
};
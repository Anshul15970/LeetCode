class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX,sum = 0;
        for(int i = 0;i<n;i++){a= min(a,nums[i]);}
        for(int i : nums){sum += i - a;}
        return sum;
    }
};
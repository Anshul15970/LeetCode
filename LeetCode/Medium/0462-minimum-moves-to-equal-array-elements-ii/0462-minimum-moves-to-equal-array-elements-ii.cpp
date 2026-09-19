class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int md = nums[n/2],sum = 0;
        for(auto &i : nums){
            if(i >= md){sum += i-md;}
            else{sum += md-i;}
        }
        return sum;
    }
};
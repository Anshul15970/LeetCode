class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),cnt = 0;
        for(int i = n-1;i>=0;i--){
            int j = 0, k = i-1;
            while(j < k){
                if((nums[j]+nums[k]) > nums[i]){cnt+=(k-j); k--;}
                else{j++;}
            }
        }
        return cnt;
    }
};
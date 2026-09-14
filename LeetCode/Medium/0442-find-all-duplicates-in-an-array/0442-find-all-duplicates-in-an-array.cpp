class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        int prev = nums[0];
        for(int i = 1;i<n;i++){
            if(prev != nums[i]){prev = nums[i];}
            else{ans.push_back(nums[i]);}
        }
        return ans;
    }
};
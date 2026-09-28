class Solution {
public:
    set<vector<int>> ans;
    vector<int> v;
    void solve(vector<int>& nums,int i){
        if(i >= nums.size()){
            if(v.size() >= 2){
            ans.insert(v);} return;}
        if(!v.size() || v.back() <= nums[i]){
            v.push_back(nums[i]);
            solve(nums,i+1);
            v.pop_back();
        }
        solve(nums,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0);
        vector<vector<int>> res;
        for(auto &i : ans){res.push_back(i);}
        return res;
    }
};
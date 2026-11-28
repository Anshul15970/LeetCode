class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        unordered_map<int,int> m;
        vector<int> nums;
        for(int i = 0;i<n;i++){if(!m.count(v[i])){nums.push_back(v[i]); m[v[i]] = i;}}
        int ans = INT_MAX;
        int p = nums.size();
        for(int i = 0;i<p;i++){
            int num = (n-1) + nums[i];
            int idx = upper_bound(nums.begin()+i,nums.end(),num)-nums.begin();
            ans = min(ans,n-(idx-i));
        }
        return ans;
    }
};
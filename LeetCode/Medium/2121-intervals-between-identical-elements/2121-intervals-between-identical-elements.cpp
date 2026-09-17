class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,pair<long long,long long>> m;
        vector<long long> ans(n,0);
        for(int i = 0;i<n;i++){
            long long count = m[nums[i]].first,sum = m[nums[i]].second;
            ans[i] = (long long)(i*count - sum);
            m[nums[i]].first++; m[nums[i]].second += i;
        }
        m.clear();
        for(int i = n-1;i>=0;i--){
            long long count = m[nums[i]].first, sum = m[nums[i]].second;
            ans[i] += (long long)sum - count*i;
            m[nums[i]].first++; m[nums[i]].second += i;
        }
        return ans;
    }
};
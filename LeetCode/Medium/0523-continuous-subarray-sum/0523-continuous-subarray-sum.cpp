class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2){return false;}
        unordered_map<int,int> m;
        vector<int> presum(n,0);
        presum[0] = nums[0];
        for(int i = 1;i<n;i++){presum[i] = nums[i]+presum[i-1];}
        m[0] = -1;
        for(int i = 0;i<n;i++){
            int a = presum[i]%k;
            if(m.find(a) != m.end()){
                if(i-m[a] >= 2){return true;}
            }
            else{m[a] = i;}
        }
        return false;
    }
};
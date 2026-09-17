class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>> m;
        int n = nums.size();
        vector<long long> ans(n,0);
        for(int i = 0;i<n;i++){m[nums[i]].push_back(i);}
        for(auto &i : m){
            vector<long long> arr = i.second;
            int s = arr.size();
            if(s == 1){continue;}
            vector<long long> prefix(s,0);
            prefix[0] = arr[0];
            for(int j = 1;j<s;j++){prefix[j] = prefix[j-1]+arr[j];}
            for(int j = 0;j<s;j++){
                long long a = (((long long)prefix[s-1]-prefix[j]) - (s-(j+1))*arr[j]) + 
                (j>0?(long long)j*arr[j] - prefix[j-1]:0);
                ans[arr[j]] = a;
            }
        }
        return ans;
    }
};
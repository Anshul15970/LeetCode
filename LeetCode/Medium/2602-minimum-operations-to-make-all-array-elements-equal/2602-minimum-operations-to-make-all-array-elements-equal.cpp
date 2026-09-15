class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),m = queries.size();
        vector<long long> prefix(n,0),ans;
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i = 0;i<m;i++){
            long long a = 0;
            int j = 0;
            int s = 0,e = n-1;
            while(s<=e){int mid = s + (e-s)/2; 
                if(nums[mid] >= queries[i]){j = mid; e = mid-1;}
                else{s = mid+1;}}
            if(j > 0){
                a += (long long)queries[i]*j - prefix[j-1];
            }
            if(j < n){
                a += (long long)prefix[n-1]-(j>0?prefix[j-1]:0) - (long long)queries[i] * (n-j);
            }
            ans.push_back(abs(a));
        }
        return ans;
    }
};
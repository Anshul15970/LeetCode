class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        vector<int> prefix(n,0);
        for(int i = 0;i<n;i++){nums[i] = nums[i]==target?1:-1;}
        prefix[0] = nums[0];
        for(int i= 1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];;
        }
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int sum = 0;
                if(i==0){sum = prefix[j];}
                else{sum = prefix[j]-prefix[i-1];}
                if(sum > 0){ans++;}
            }
        }
        return ans;
    }
};
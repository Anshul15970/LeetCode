class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        int sum = 0,ans = 0;
        m[0] = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){sum += -1;}
            else{sum += 1;}
            if(m.find(sum) != m.end()){ans = max(ans,i-m[sum]);}
            else{m[sum] = i;}
        }
        return ans;
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0],b = nums[n-1];
        int s = -1,e = -1;
        for(int i = 0;i<n;i++){
            if(a > nums[i]){e = i;}
            else{a = nums[i];}
        }
        for(int i = n-2;i>=0;i--){
            if(b < nums[i]){s = i;}
            else{b = nums[i];}
        }
        if(s == -1 || e == -1){return 0;}
       return e-s+1;
    }
};
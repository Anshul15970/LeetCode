class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        if(n == 2){return min(nums[0],nums[1]);}
        int s = 0,e = n-1,ans = INT_MAX;
        if(nums[s] < nums[e]){return nums[s];}
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mid-1 >= 0 && mid+1 < n && (nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])){return nums[mid];}
            else if(mid-1 >= 0 && mid+1 < n &&
            (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])){return nums[mid+1];}
            else if(nums[s] > nums[mid]){
                e = mid;
            }
            else{s = mid;}
        }
        return nums[0];
    }
};
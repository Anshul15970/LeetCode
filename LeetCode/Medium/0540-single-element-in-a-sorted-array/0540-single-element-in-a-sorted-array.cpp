class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0,e = n-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(m - 1 >= 0 && nums[m] == nums[m-1]){
                if(m%2 == 0){e = m-1;}
                else{s = m+1;}
            }
            else if(m+1 < n && nums[m] == nums[m+1]){
                if((n-m+1)%2 == 0){s = m+1;}
                else{e = m-1;}
            }
            else{return nums[m];}
        }
        return -1;
    }
};
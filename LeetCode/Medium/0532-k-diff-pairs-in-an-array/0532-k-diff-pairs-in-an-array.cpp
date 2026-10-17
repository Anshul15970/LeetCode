class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int s = i+1,e = n-1;
            while(s <= e){
                int mid = s + (e-s)/2;
                if(nums[i]-k == nums[mid]){st.insert({min(nums[mid],nums[i]),max(nums[mid],nums[i])}); break;}
                else if(nums[i]-k < nums[mid]){e = mid-1;}
                else{s = mid+1;}
            }
            s = i+1,e = n-1;
            while(s <= e){
                int mid = s + (e-s)/2;
                if(nums[i]+k == nums[mid]){st.insert({min(nums[mid],nums[i]),max(nums[mid],nums[i])}); break;}
                else if(nums[i]+k < nums[mid]){e = mid-1;}
                else{s = mid+1;}
            }
        }
        return st.size();
    }
};
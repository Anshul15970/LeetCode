class Solution {
public:
    int cnt = 0;
    void mergesort(vector<int>& nums,int l,int mid,int r){
        vector<int> temp; 
        int i = l,j = mid+1;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){temp.push_back(nums[i]); i++;}
            else{temp.push_back(nums[j]); j++;}
        }
        while(i <= mid){temp.push_back(nums[i]); i++;}
        while(j <= r){temp.push_back(nums[j]); j++;}
        for(int k = 0;k<temp.size();k++){
            nums[l+k] = temp[k];
        }
    }
    void merge(vector<int>& nums,int l,int r){
        if(l >= r){return;}
        int mid = l + (r-l)/2;
        merge(nums,l,mid);
        merge(nums,mid+1,r);
        int j = mid+1;
        for(int i = l;i<=mid;i++){
            while( j <= r && 1LL * nums[i] > 2 * 1LL * nums[j]){j++;}
            cnt += j - (mid+1);
        }
        mergesort(nums,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return cnt;
    }
};
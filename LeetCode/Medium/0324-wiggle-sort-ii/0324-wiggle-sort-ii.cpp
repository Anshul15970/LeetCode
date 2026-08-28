class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        int s = (n-1)/2;
        int l = n-1;
        for(int i = 0;i<n;i++){
            if(i%2==0){
                nums[i] = arr[s--];
            }
            else{
                nums[i] = arr[l--];
            }
        }
       
    }
};
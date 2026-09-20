class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(),cnt = 0;
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                m[nums1[i]+nums2[j]]++;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int sum = -(nums3[i]+nums4[j]);
                if(m[sum]>0){cnt+=m[sum];}
            }
        }
        return cnt;
    }
};
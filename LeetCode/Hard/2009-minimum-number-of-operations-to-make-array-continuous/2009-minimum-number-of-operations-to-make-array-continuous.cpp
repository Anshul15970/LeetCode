class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        unordered_map<int,int> m;
        vector<int> nums;
        for(int i = 0;i<n;i++){if(!m.count(v[i])){nums.push_back(v[i]); m[v[i]] = i;}}
        int ans = INT_MAX;
        int p = nums.size();
        for(int i = 0;i<p;i++){
            int num = (n-1) + nums[i];
            int s = i,e = p-1;
            bool found = false;
            int idx = -1;
            while(s <= e){
                int mid = s + (e-s)/2;
                if(nums[mid] == num){found = true; ans = min(ans,n-(mid-i+1)); break;}
                else if(nums[mid] < num){idx = max(idx,mid); s = mid+1;}
                else{e = mid-1;}
            }
            if(!found){ans = min(ans,n-(idx-i+1));}
        }
        return ans;
    }
};
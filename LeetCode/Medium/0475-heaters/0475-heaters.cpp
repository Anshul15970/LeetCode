class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = INT_MIN;
        int n = houses.size(),m = heaters.size();
        for(int i = 0;i<n;i++){
            int r = INT_MAX;
            for(int j = 0;j<m;j++){
                r = min(r,abs(houses[i]-heaters[j]));
            }
            ans = max(ans,r);
        }
        return ans;
    }
};
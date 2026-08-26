class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            int cntl1 = 0,cntl2 = 0,cntr1=0,cntr2 = 0;
            for(int j = 0;j<i;j++){
                if(rating[i] < rating[j]){cntl1++;}
                else if(rating[i] > rating[j]){cntl2++;}
            }
            for(int j = i+1;j<n;j++){
                if(rating[i] > rating[j]){cntr1++;}
                else if(rating[i] < rating[j]){cntr2++;}
            }
            ans += (cntl1 * cntr1) + (cntl2 * cntr2);
        }
        return ans;
    }
};
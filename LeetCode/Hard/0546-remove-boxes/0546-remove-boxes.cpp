class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int l,int r,int cnt,vector<int>& boxes){
        if(l > r){return 0;}
        while(l+1 <= r && boxes[l] == boxes[l+1]){cnt++; l++;}
        if(dp[l][r][cnt] != -1){return dp[l][r][cnt];}
        int ans = ((cnt+1) * (cnt+1)) + solve(l+1,r,0,boxes);
        for(int i = l+1;i<=r;i++){
            if(boxes[l] == boxes[i]){
                ans = max(ans,solve(i,r,cnt+1,boxes) + solve(l+1,i-1,0,boxes));
            }
        }
        return dp[l][r][cnt] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve(0,n-1,0,boxes);
    }
};
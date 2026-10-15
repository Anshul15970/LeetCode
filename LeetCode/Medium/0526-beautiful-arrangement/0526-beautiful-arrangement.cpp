class Solution {
public:
    int ans = 0;
    vector<bool> used;
    void solve(int n,int i){
        if(i > n){ans++; return;}
        for(int j = 1;j<=n;j++){
            if(used[j]){continue;}
            if(j%i == 0 || i%j == 0){
                used[j] = true;
                solve(n,i+1);
                used[j] = false;
            }
        }
    }
    int countArrangement(int n) {
        used.assign(n+1,false);
        solve(n,1);
        return ans;
    }
};
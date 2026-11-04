class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.length();
        vector<int> prefix(n+1,0),suffix(n+1,0);
        for(int i = 0;i<n;i++){prefix[i+1] = prefix[i] + (c[i]=='N'); }
        for(int i = n-1;i>=0;i--){suffix[i] = suffix[i+1] + (c[i]=='Y'); }
        int ans = INT_MAX,index = INT_MAX;
        for(int i = 0;i<=n;i++){
            int sum = prefix[i] + suffix[i];
            if(ans > sum){ans = sum; index = i;}
        }
        return index;
    }
};
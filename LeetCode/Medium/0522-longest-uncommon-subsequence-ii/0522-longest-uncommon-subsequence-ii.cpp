class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for(int i = 0;i<n;i++){
            string s = strs[i];
            int m = s.size(), cnt = 0;
            for(int j = 0;j<n;j++){
                if(i == j){continue;}
                string s1 = strs[j];
                int l = s1.size();
                int p = 0,q = 0;
                while(p < l && q < m){if(s[q] == s1[p]){q++;} p++;}
                if(q != m){cnt++;}
            }
            if(cnt == n-1){ans = max(ans,m);}
        }
        return ans;
    }
};
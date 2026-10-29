class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long,int> mp;
        for(int i = 0;i<n;i++){
            int m = wall[i].size();
            if(m == 1){continue;}
            vector<long long> a(m,0);
            a[0] = wall[i][0]; mp[a[0]]++;
            for(int j = 1;j<m-1;j++){a[j] = a[j-1]+wall[i][j];mp[a[j]]++;}
        }
        int cnt = 0;
        for(auto &i : mp){cnt = max(i.second,cnt);}
        return n-cnt;
    }
};
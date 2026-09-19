class Solution {
public:

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();
        for(int i = 0;i<n;i++){
            unordered_map<double,int> m;
            for(int j = 0;j<n;j++){
                int dx = points[i][0],dy = points[i][1],cx = points[j][0],cy = points[j][1];
                long a = (dx-cx)*(dx-cx) + (dy-cy)*(dy-cy);
                m[a]++;
            }
            for(auto &k : m){ int cnt = k.second; sum += cnt*(cnt-1);}
        }
        return sum;
    }
};
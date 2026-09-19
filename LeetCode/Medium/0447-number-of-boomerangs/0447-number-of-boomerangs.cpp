class Solution {
public:
    double dist(vector<int> a,vector<int> b){
        return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();
        for(int i = 0;i<n;i++){
            unordered_map<double,int> m;
            for(int j = 0;j<n;j++){
                if(j == i){continue;}
                double a = dist(points[i],points[j]);
                m[a]++;
            }
            for(auto &k : m){ int cnt = k.second;
            if(cnt >= 2){
                sum += cnt*(cnt-1);
            }}
        }
        return sum;
    }
};
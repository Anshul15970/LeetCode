class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> m(n,0);
        for(int i = 0;i<n;i++){
            m[edges[i]] += i;
        }
        long long ans = 0;
        long long index = n+1;
        for(int i = 0;i<n;i++){
            if(ans < m[i]){
                ans = m[i];
                index = i;
            }
            if(ans == m[i]){
                index = min(index,(long long)i);
            }
        }
        return index;
    }
};
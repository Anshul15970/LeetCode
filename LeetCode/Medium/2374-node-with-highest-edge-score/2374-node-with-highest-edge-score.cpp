class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long long,long long> m;
        int n = edges.size();
        for(int i = 0;i<n;i++){
            m[edges[i]] += i;
        }
        long long ans = 0;
        long long index = n+1;
        for(auto &i : m){
            if(ans < i.second){
                ans = i.second;
                index = i.first;
            }
            if(ans == i.second){
                index = min(index,i.first);
            }
        }
        return index;
    }
};
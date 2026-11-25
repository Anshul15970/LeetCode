class Solution {
public:
    vector<int> solve(vector<int>& edges, int node){
        int n = edges.size();
        int d = 0;
        vector<int> dist(n,-1);
        while(node != -1 && dist[node] == -1){
            dist[node] = d++;
            node = edges[node];
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1 = solve(edges,node1);
        vector<int> d2 = solve(edges,node2);
        int n = edges.size();
        int ans = INT_MAX, idx = -1;
        for(int i = 0;i<n;i++){
            if(d1[i] != -1 && d2[i] != -1){
            int m = max(d1[i],d2[i]);
            if(ans > m){
                ans = m;
                idx = i;}
            }
        }
        return idx;
    }
};
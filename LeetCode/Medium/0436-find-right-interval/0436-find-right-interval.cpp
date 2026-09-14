class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& v) {
        int n = v.size();
        unordered_map<int,int> m;
        for(int i = 0;i<n;i++){m[v[i][0]] = i;}
        vector<int> ans(n,-1);
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++){
            int s = i,e = n-1;
            if(s < n){
                while(s<=e){
                    int mid = s + (e-s)/2;
                    if(v[mid][0] == v[i][1]){ans[m[v[i][0]]] = m[v[mid][0]]; break;}
                    else if(v[mid][0] > v[i][1]){
                        int idx1 = ans[m[v[i][0]]],idx2 = m[v[mid][0]];
                        if(idx1 != -1){ans[m[v[i][0]]] = min(idx1,idx2);}
                        else{ans[m[v[i][0]]] = idx2;}
                        e = mid-1;
                    }
                    else{s = mid+1;}
                }
            }
        }
        return ans;
    }
};
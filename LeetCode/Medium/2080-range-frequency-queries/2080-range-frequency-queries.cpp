class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i =0;i<n;i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(m.find(value) == m.end()){return 0;}
        vector<int> &v = m[value];
        auto l = lower_bound(v.begin(),v.end(),left);
        auto r = upper_bound(v.begin(),v.end(),right);
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
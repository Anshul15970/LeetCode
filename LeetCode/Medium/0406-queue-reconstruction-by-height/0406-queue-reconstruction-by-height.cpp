class Solution {
public:
    vector<int> segtree;
    void buildtree(int idx,int l,int r){
        if(l==r){
            segtree[idx] = 1; return;}
        int mid = l + (r-l)/2;
        buildtree(2*idx,l,mid);
        buildtree(2*idx + 1,mid+1,r);
        segtree[idx] = segtree[2*idx] + segtree[2*idx + 1]; 
    }

    int query(int idx,int l,int r,int val){
        if(l==r){return l;}
        int mid = l + (r-l)/2;
        int l_child = 2*idx,l_wt = segtree[l_child];
        if(val <= l_wt){
            return query(l_child,l,mid,val);
        }
        else{
            return query(l_child+1,mid+1,r,val - l_wt);
        }
    }

    void update(int idx,int l,int r,int pos){
        if(l==r){segtree[idx] = 0; return;}
        int mid = l + (r-l)/2;
        if(pos <= mid){update(2*idx,l,mid,pos);}
        else{update(2*idx + 1,mid+1,r,pos);}
        segtree[idx] = segtree[2*idx] + segtree[2*idx + 1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        segtree.assign(4*n,0);
        sort(people.begin(),people.end(),[](vector<int> &a,vector<int> &b){
            if(a[0] != b[0]){return a[0] < b[0];}
            return a[1] > b[1];});
        vector<vector<int>> ans(n);
        if(!n){return ans;}
        buildtree(1,0,n-1);
        for(const auto v: people){
            int pos = v[1] + 1;
            int idx = query(1,0,n-1,pos);
            ans[idx] = v;
            update(1,0,n-1,idx);
        }
        return ans;
    }
};
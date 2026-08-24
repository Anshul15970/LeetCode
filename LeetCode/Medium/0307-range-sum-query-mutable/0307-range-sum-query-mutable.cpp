class NumArray {
public:
    vector<int> segtree;
    int n;
   void buildtree(int idx,int l,int r,vector<int> &nums){
    if(l==r){segtree[idx] = nums[l]; return;}
        int mid = l + (r-l)/2;
        buildtree(2*idx,l,mid,nums);
        buildtree(2*idx+1,mid+1,r,nums);
        segtree[idx] = segtree[2*idx] + segtree[2*idx+1];
   }

   void updatequery(int idx,int l,int r,int pos,int val){
        if(l==r){segtree[idx] = val; return;}
        int mid = l + (r-l)/2;
        if(pos <= mid){
            updatequery(2*idx,l,mid,pos,val);
        }
        else{
            updatequery(2*idx+1,mid+1,r,pos,val);
        }
        segtree[idx] = segtree[2*idx] + segtree[2*idx+1];
   }

   int query(int idx,int l,int r,int ql,int qr){
        if(r < ql || l > qr){return 0;}
        if(l >= ql && r <= qr){return segtree[idx];}
        int mid = l + (r-l)/2;
        return query(2*idx,l,mid,ql,qr) + query(2*idx+1,mid+1,r,ql,qr);
   }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.assign(4*n,0);
        buildtree(1,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updatequery(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
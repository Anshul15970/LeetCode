class Solution {
public:
    vector<int> segtree;
    void buildtree(int idx,int l,int r,vector<int> &baskets){
        if(l==r){segtree[idx] = baskets[l]; return;}
        int mid = l + (r-l)/2;
        buildtree(2*idx,l,mid,baskets);
        buildtree(2*idx+1,mid+1,r,baskets);
        segtree[idx] = max(segtree[2*idx],segtree[2*idx+1]);
    }
    int index(int idx,int l,int r,int fruit){
        if(segtree[idx] < fruit){return -1;}
        if(l == r){return l;}
        int mid = l + (r-l)/2;
        if(segtree[2*idx] >= fruit){
            return index(2*idx,l,mid,fruit);}
        else{
            return index(2*idx+1,mid+1,r,fruit);
        }
    }

    void update(int idx,int l,int r,int pos){
        if(l==r){segtree[idx] = -1; return;}
        int mid = l + (r-l)/2;
        if(pos <= mid){
            update(2*idx,l,mid,pos);
        }
        else{
            update(2*idx+1,mid+1,r,pos);
        }
        segtree[idx] = max(segtree[2*idx],segtree[2*idx + 1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        segtree.assign(4*n, 0);
        buildtree(1,0,n-1,baskets);
        int unplaced = 0;
        for(int i = 0;i<n;i++){
            int idx = index(1,0,n-1,fruits[i]);
            if(idx == -1){
                unplaced++;
            }
            else{
                update(1,0,n-1,idx);
            }
        }
        return unplaced;
    }
};
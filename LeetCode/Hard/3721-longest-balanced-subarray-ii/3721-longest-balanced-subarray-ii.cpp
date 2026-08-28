class Solution {
public:
    vector<int> segmin,segmax,lazy;
    int n;
    void propagate(int i,int l,int r){
        if(lazy[i]!=0){
            segmin[i]+=lazy[i];
            segmax[i]+=lazy[i];
            if(l!=r){
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;
        }
    }
    void update(int s,int e,int i,int l,int r,int val){
        propagate(i,l,r);
        if(l>e || r<s){return;}
        if(l>=s && r<=e){
            lazy[i]+=val;
            propagate(i,l,r);
            return;
        }
        int mid = l + (r-l)/2;
        update(s,e,2*i+1,l,mid,val);
        update(s,e,2*i+2,mid+1,r,val);
        segmin[i]=min(segmin[2*i+1],
                     segmin[2*i+2]);
        segmax[i]  = max(segmax[2*i+1],
                  segmax[2*i+2]);
    }
    int find(int i, int l,int r){
        propagate(i,l,r);
        if(segmin[i]>0 || segmax[i]<0){
            return -1;
        }
        if(l==r){return l;}
        int mid = l+(r-l)/2;
        int left=find(2*i+1,l,mid);
        if(left!=-1){return left;}
        return find(2*i+2,mid+1,r);
    }
    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        segmin.assign(4*n,0);
        segmax.assign(4*n,0);
        lazy.assign(4*n,0);
        int maxl = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int val = (nums[i]%2==0)?
            1:-1;
            int prev = -1;
            if(m.count(nums[i])){
                prev=m[nums[i]];
            }
            if(prev!=-1){
                update(0,prev,0,0,n-1,-val);
            }
            update(0,i,0,0,n-1,val);
            int left = find(0,0,n-1);
            if(left!=-1){
                maxl = max(maxl,i-left+1);
            }
            m[nums[i]]=i;
        }
        return maxl;
    }
};
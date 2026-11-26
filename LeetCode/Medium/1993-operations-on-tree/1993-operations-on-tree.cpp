class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> adj;
    vector<int> locked;
    LockingTree(vector<int>& p) {
        parent = p;
        int n = p.size();
        adj.resize(n);
        locked.resize(n,0);
        for(int i = 1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
    }
    bool lock(int num, int user) {
        if(locked[num] != 0){return false;}
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(locked[num] != user){return false;}
        locked[num] = 0;
        return true;
    }
    void dfs(int p,bool& f){
        for(int i : adj[p]){
            if(locked[i] != 0){locked[i] = 0; f = true;}
            dfs(i,f);
        }
    }
    
    bool upgrade(int num, int user) {
        if(locked[num] != 0){return false;}
        int p = parent[num];
        while(p!=-1){
            if(locked[p] != 0){return false;}
            p = parent[p];
        }
        bool f = false;
        dfs(num,f);
        if(!f){return false;}
        locked[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
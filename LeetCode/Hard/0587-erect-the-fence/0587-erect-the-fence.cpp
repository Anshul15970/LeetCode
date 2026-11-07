class Solution {
public:
    int cross(vector<int>& a,vector<int>& b,vector<int>& c){
        return ((b[0]-a[0])*(c[1]-a[1])) - ((b[1]-a[1])*(c[0]-a[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3){return trees;}
        vector<vector<int>> l,u;
        sort(trees.begin(),trees.end());
        for(auto &p : trees){
            while(l.size() >= 2 && cross(l[l.size()-2],l.back(),p) < 0){l.pop_back();}
            l.push_back(p);
        }

        for(int i = trees.size()-1;i>=0;i--){
            while(u.size() >= 2 && cross(u[u.size()-2],u.back(),trees[i]) < 0){u.pop_back();}
            u.push_back(trees[i]);
        }
        set<vector<int>> s;
        for(auto &p : l){s.insert(p);}
        for(auto &p : u){s.insert(p);}
        vector<vector<int>> ans(s.begin(),s.end());
        return ans; 
    }
};
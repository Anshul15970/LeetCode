class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(),n = s2.length();
        sort(s1.begin(),s1.end());
        string a = s2.substr(0,m);
        sort(a.begin(),a.end());
        if(a == s1){return true;}
        vector<int> v(26,0),idx;
        for(auto i : s1){v[i-'a']++;}
        for(int i = 0;i<n;i++){if(v[s2[i]-'a']>0){idx.push_back(i);}}
        for(int i = 0;i<idx.size();i++){
            if(idx[i]+m <= n){
            string a = s2.substr(idx[i],m);
            sort(a.begin(),a.end());
            if(s1 == a){return true;}}
        }
        return false;
    }
};
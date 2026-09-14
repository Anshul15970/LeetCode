class Solution {
public:
    bool allzero(vector<int> &v){
        for(int &i : v){if(i!=0){return false;}}
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(),m = p.length();
        vector<int> v(26,0),ans;
        for(char &i : p){v[i-'a']++;}
        int i = 0,j = 0;
        int count = 0;
        while(j < n){
            v[s[j]-'a']--;
            if(j-i+1 == m){
                if(allzero(v)){ans.push_back(i);}
                v[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int> v(26,0);
        int len = 1;
        v[s[0]-'a'] = 1;
        for(int i = 1;i<n;i++){
            if(s[i]-s[i-1] == 1 || s[i-1] == 'z' && s[i] == 'a'){len++;}
            else{len = 1;}
            v[s[i]-'a'] = max(len,v[s[i]-'a']);
        }
        int sum = 0;
        for(int i : v){sum += i;}
        return sum;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1){return n;}
        char prev = chars[0];
        int k = 0,i = 0;
        while(i<n){
            int j = i,cnt = 0;
            while(j < n && prev == chars[j]){
                cnt++; j++;}
            if(cnt > 1){string s; s += prev; s += to_string(cnt);
            for(char &c : s){chars[k++] = c;}}
            else{chars[k++] = prev;}
            if(j<n){
            prev = chars[j];}
            i=j;
        }
        return k;
    }
};
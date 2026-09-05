class Solution {
public:
    vector<int> LPS(string a){
        int i = 1,len = 0;
        vector<int> lps(a.length(), 0);
        while(i<a.length()){
            if(a[i] == a[len]){len++; lps[i] = len; i++;}
            else if(len != 0){len = lps[len-1];}
            else{lps[i] = 0; i++;}
        }
        return lps;}
    int repeatedStringMatch(string a, string b) {
        int m = b.length();
        string s = a;
        int cnt = 1;
        while(a.length()<m){a += s; cnt++;}
        vector<int> lps = LPS(b);
        int n = a.length();
        int i = 0,j = 0;
        while(i<n){
            if(a[i] == b[j]){i++; j++;
               if(j == m){return cnt;}}
            else if(j != 0){j = lps[j-1];}
            else{i++;}
        }
        a += s; cnt++; i = 0; j = 0; n = a.length();
        while(i<n){
            if(a[i] == b[j]){i++; j++;
               if(j == m){return cnt;}}
            else if(j != 0){j = lps[j-1];}
            else{i++;}
        }
        return -1;
    }
};
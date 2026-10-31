class Solution {
public:
    long func(long fh,bool f){
        long ans = fh;
        if(!f){fh /= 10;}
        while(fh){
            int d = fh%10;
            ans = ans * 10 + d;
            fh /= 10;
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int l = n.length();
        int mid = l/2;
        int fhl = (l%2 == 0)? mid : mid+1;
        long fh = stol(n.substr(0,fhl));
        vector<long> v;
        v.push_back(func(fh,l%2 == 0));
        v.push_back(func(fh+1,l%2 == 0));
        v.push_back(func(fh-1,l%2 == 0));
        v.push_back((long)pow(10,l-1)-1);
        v.push_back((long)pow(10,l)+1);
        long diff = LONG_MAX;
        long result = INT_MAX;
        long num = stol(n);
        for(long i : v){
            if(i == num){continue;}
            if(abs(i - num) < diff){
                diff = abs(i-num);
                result = i;
            }
            else if(abs(i - num) == diff){
                result = min(result,i);
            }
        }
        return to_string(result);
    }
};
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int temp = n;
        while(n){v.push_back(n%10); n/=10;}
        reverse(v.begin(),v.end());
        int s = v.size();
        long long ans = 0;
        int i = s-2;
        while(i >= 0 && v[i] >= v[i+1]){i--;}
        if(i == -1){return -1;}
        int j = s-1;
        while(j >= 0 && v[j] <= v[i]){j--;}
        swap(v[i],v[j]);
        reverse(v.begin()+i+1,v.end());
        for(int k : v){ans = ans*10 + k;}
        if(ans > INT_MAX){return -1;}
        return ans;
    }
};
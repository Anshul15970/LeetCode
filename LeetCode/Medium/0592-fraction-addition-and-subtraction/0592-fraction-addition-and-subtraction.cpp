class Solution {
public:
    pair<long long, long long> decimalToFraction(double x) {
    const long long MAX_DEN = 1000000;
    long long h1 = 1, h2 = 0;
    long long k1 = 0, k2 = 1;
    double b = x;
    while (true) {
        long long a = floor(b);
        long long h = a * h1 + h2;
        long long k = a * k1 + k2;
        if (k > MAX_DEN)
            break;
        if (abs(x - (double)h / k) < 1e-10)
            return {h, k};
        h2 = h1;
        h1 = h;
        k2 = k1;
        k1 = k;
        double fractional = b - a;
        if (fractional < 1e-15)
            break;
        b = 1.0 / fractional;
    }
    return {h1, k1};
}

    string fractionAddition(string exp) {
        stack<double> v;
        int n = exp.length();
        char s = 'p';
        int k = 0;
        string s1,s2;
        if(exp[0] == '-' || exp[0] == '+'){ s1 += exp[0]; k = 1; }
        while(k<n && exp[k] != '/'){s1 += exp[k]; k++;}
        k++;
        while(k<n && exp[k] != '+' && exp[k] != '-'){s2 += exp[k]; k++;}
        double a = stod(s1)/stod(s2);
        v.push(a);
        if(k<n){s = exp[k];}
        for(int i = k;i<n;i++){
            if(i-1>= 0 && i+1 < n && exp[i] == '/'){
                string s1,s2;
                int j = i-1;
                while(j>= 0 && (exp[j] >= '0' && exp[j] <= '9')){s1+=exp[j]; j--;}
                reverse(s1.begin(),s1.end());
                j = i+1;
                while(j<n && exp[j]>='0' && exp[j] <= '9'){s2 += exp[j]; j++;}
                double a = stod(s1)/stod(s2);
                if(v.size() && s != 'p'){double b = v.top(); v.pop(); 
                if(s == '+'){v.push(b+a);}
                else{v.push(b-a);}}
                else{v.push(a);}
                if(j < n){s = exp[j];}
            }
        }
        auto [num,den] = decimalToFraction(v.top());
        return to_string(num) + "/" + to_string(den);
    }
};
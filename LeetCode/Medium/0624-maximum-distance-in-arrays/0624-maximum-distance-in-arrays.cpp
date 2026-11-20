class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int m1 = INT_MIN, m2 = INT_MAX,n1 = INT_MIN,n2 = INT_MAX,index1 = -1,index2 = -1;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int m = arr[i].size();
            if(m1 < arr[i][m-1]){m1 = arr[i][m-1]; index1 = i;}
            if(m2 > arr[i][0]){m2 = arr[i][0]; index2 = i;}
        }
        int index3 = -1, index4 = -1;
        for(int i = 0;i<n;i++){
            int m = arr[i].size();
            if(index1 == i || index2 == i){continue;}
            if(n1 < arr[i][m-1]){n1 = arr[i][m-1];}
            if(n2 > arr[i][0]){n2 = arr[i][0];}
        }
        cout << m1 << " " << m2 << endl;
        cout << n1 << " " << n2;
        if(index1 != index2){return max(abs(m1-m2),abs(m2-m1));}
        return max({abs(m1-n2),abs(n2-m1),abs(m2-n1),abs(n1-m2)});
    }
};
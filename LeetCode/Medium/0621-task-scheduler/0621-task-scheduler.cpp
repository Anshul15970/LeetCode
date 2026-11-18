class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        vector<int> v(26,0);
        for(char &c : t){v[c-'A']++;}
        priority_queue<int> pq;
        for(int i : v){if(i > 0){pq.push(i);}}
        int cnt = 0;
        while(pq.size()){
            vector<int> z; 
            for(int i = 0;i<=n;i++){
                if(pq.size()){
                    int f = pq.top(); 
                    pq.pop();
                    f--;
                    z.push_back(f);
                }
            }
            for(int &i : z){if(i>0){pq.push(i);}}
            if(pq.empty()){cnt += z.size();}
            else{cnt += n+1;}
        }
        return cnt;
    }
};
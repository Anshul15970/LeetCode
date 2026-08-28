class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mlen = INT_MIN;
        int n = words.size();
        vector<int> mask(n,0);
        for(int i = 0;i<n;i++){
            for(char c : words[i]){mask[i] |= (1 << (c - 'a'));}
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((mask[i] & mask[j]) == 0){
                    mlen = max(mlen,(int)(words[i].length()*words[j].length()));}
            }
        }
        return mlen==INT_MIN?0:mlen;
    }
};
class Solution {
    public int findMinDifference(List<String> t) {
        int n = t.size();
        int ans = Integer.MAX_VALUE;
        List<Integer> v = new ArrayList<>();
        for(String s : t){
            int a = Integer.parseInt(s.substring(0,2));
            int b = Integer.parseInt(s.substring(3,5));
            v.add(a*60 + b);
        }
        Collections.sort(v);
        for(int i = 1;i<n;i++){
            ans = Math.min(ans,Math.abs(v.get(i-1)-v.get(i)));
        }
        ans = Math.min(ans,1440 - Math.abs(v.get(n-1) - v.get(0)));
        return ans;
    }
}
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int n = wall.size();
        HashMap<Long,Integer> mp = new HashMap<>();
        for(int i = 0;i<n;i++){
            int m = wall.get(i).size();
            if(m == 1){continue;}
            long sum = 0;
            for(int j = 0;j<m-1;j++){sum += wall.get(i).get(j);
               mp.put(sum,mp.getOrDefault(sum,0)+1);
            }
        }
        int cnt = 0;
        for(int v : mp.values()){cnt = Math.max(cnt,v);}
        return n-cnt;
    }
}
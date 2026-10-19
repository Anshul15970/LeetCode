class Solution {
    public int arrayNesting(int[] nums) {
        int n = nums.length;
        int cnt1 = 0;
        boolean[] vis = new boolean[n];
        for(int i : nums){
            if(vis[i]){continue;}
            Queue<Integer> q = new LinkedList<>();
            int cnt = 1;
            q.offer(i);
            vis[i] = true;
            while(!q.isEmpty()){
                int node = q.poll();
                int next = nums[node];
                if(!vis[next]){q.offer(next); vis[next] = true; cnt++;}
            }
            cnt1 = Math.max(cnt1,cnt);
        }
        return cnt1;
    }
}
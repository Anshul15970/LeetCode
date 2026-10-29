class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        n = len(wall)
        mp = {}
        for i in range(n):
            m = len(wall[i])
            if(m == 1):
                continue
            total = 0
            for j in range(m-1):
                total += wall[i][j]
                mp[total] = mp.get(total,0)+1
        
        cnt = 0
        for v in mp.values():
            cnt = max(cnt,v)
        return n-cnt
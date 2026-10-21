class Solution:
    def findMinDifference(self, t: list[str]) -> int:
        v = []
        ans = float('inf')
        for s in t:
            a, b = map(int,s.split(':'))
            v.append(a*60 + b)
        v.sort()
        for i in range(1,len(v)):
            ans = min(ans,abs(v[i]-v[i-1]))
        ans = min(ans,1440 - abs(v[len(v)-1]-v[0]))
        return ans
        
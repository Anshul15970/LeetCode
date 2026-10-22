class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if(n==1):
            return 0
        p = self.kthGrammar(n-1,(k+1)//2)
        if(k%2 != 0):
            return p
        return 1-p
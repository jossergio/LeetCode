class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        c1 = Counter (s)
        c2 = Counter (t)
        for c in c2.keys ():
            if c2 [c] - c1.get (c, 0) == 1:
                return c
        return 0 # Não deve chegar aqui


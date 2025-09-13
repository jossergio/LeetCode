class Solution:
    def maxFreqSum(self, s: str) -> int:
        vogais = set (['a', 'e', 'i', 'o', 'u'])
        v, c = 0, 0
        for l, q in Counter (s).items ():
            if l in vogais:
                if q > v:
                    v = q
            else:
                if q > c:
                    c = q
        return v + c

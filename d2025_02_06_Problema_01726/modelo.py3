class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        def fat (n: int):
            r = 1
            while n > 1:
                r *= n
                n -= 1
            return r
        d = defaultdict (int)
        for i, v1 in enumerate (nums):
            for v2 in nums [i + 1:]:
                d [v1 * v2] += 1
        resposta = 0
        for v in d.values ():
            if v > 1: # Abaixo, não forma dupla
                resposta += (fat (v) // fat (v - 2)) * 4
        return resposta
    
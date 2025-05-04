class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        pares = defaultdict (list)
        for i, v in enumerate (nums):
            pares [v].append (i)
        resposta = 0
        for p in pares.values ():
            for i, v1 in enumerate (p):
                for v2 in p [i + 1:]:
                    if (v1 * v2) % k == 0:
                        resposta += 1
        return resposta
    
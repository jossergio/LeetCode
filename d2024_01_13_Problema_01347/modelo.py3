class Solution:
    def minSteps(self, s: str, t: str) -> int:
        sCount = defaultdict (int, Counter (s))
        tCount = defaultdict (int, Counter (t))
        resposta = 0
        for i, v in tCount.items ():
            if v > sCount [i]:
                resposta += v - sCount [i]
        return resposta
    

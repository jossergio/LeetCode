class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        pares = defaultdict (int)
        resposta = 0
        for d in dominoes:
            tmp = 0
            if d [0] > d [1]:
                tmp = d [1] * 12 + d [0] # Inverte
            else:
                tmp += d [0] * 12 + d [1]
            resposta += pares [tmp]
            pares [tmp] += 1
        return resposta

class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        possiveis = sorted (set (range (1, n + 1)) - set (banned))
        soma = 0
        resposta = 0
        for v in possiveis:
            soma += v
            if soma > maxSum:
                break
            resposta += 1
        return resposta
    

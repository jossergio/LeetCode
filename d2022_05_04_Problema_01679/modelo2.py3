from collections import Counter

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        
        resposta = 0
        
        # Transforma em um dicionário
        c = Counter (nums)
        
        # Para o laço ir até um certo valor; não vai até a metade em pares
        ns = set ([n for n in nums if n < (k + 1) // 2])
        
        for v in ns:
            resposta += min (c [v], c [k - v])
            
        if k % 2 == 0:
            resposta += c [k // 2] // 2
            
        return resposta
    

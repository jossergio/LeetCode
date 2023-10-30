class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        
        def nBits (i: int):
            resposta = 0
            while (i > 0):
                if (i % 2 == 1):
                    resposta += 1
                i = i // 2
            return resposta
        
        return sorted (arr, key = lambda a:  (nBits (a), a)) # Retorna um tupla
    

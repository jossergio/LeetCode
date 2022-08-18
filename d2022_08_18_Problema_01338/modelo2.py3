class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        contagem = Counter (arr).values ()
        
        limite = len (arr) // 2
        resposta = 0
        
        for item in sorted (contagem, reverse = True):
            resposta += 1
            limite -= item
            if limite <= 0:
                break
            
        return resposta
        

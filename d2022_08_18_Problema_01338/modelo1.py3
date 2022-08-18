class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        contagem = Counter (arr)
        
        limite = len (arr) // 2
        resposta = 0
        contador = 0
        
        for item in sorted (contagem.items (), key = lambda i: i [1], reverse = True):
            resposta += 1
            contador += item [1]
            if contador >= limite:
                break
            
        return resposta
        

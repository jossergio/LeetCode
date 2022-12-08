class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len (nums)
        if n < 2:
            return 0 # Não há 2a parte
        soma1 = nums [0]
        soma2 = sum (nums [1:]) # Segundo; 0-based
        indice = 1 # 1-based
        mediaAcum = abs (soma1 - (soma2 // (n - indice))) # Primeiro; referência
        resposta = 0
        while indice < n: # 0-based
            soma1 += nums [indice]
            soma2 -= nums [indice] # Aqui, 0-based
            indice += 1
            if indice == n:
                mediaAtual = abs ((soma1 // indice) - soma2)
            else:
                mediaAtual = abs ((soma1 // indice) - (soma2 // (n - indice)))
            if mediaAtual < mediaAcum:
                resposta = indice - 1 # 0-based
                mediaAcum = mediaAtual
        
        return resposta
        

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        resposta = 0
        for a in range (len (strs [0])):
            for b in range (1, len (strs)): # Inicia da segunda linha
                if ord (strs [b][a]) < ord (strs [b - 1][a]):
                    resposta += 1 # Tem que tirar essa coluna
                    break # Já sabe que tem que tirar; sai e vai para a próxima coluna
        return resposta
    
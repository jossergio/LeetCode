class Solution:
    def compressedString(self, word: str) -> str:
        atual = list ()
        etapas = list ()
        for c in word:
            if len (atual) == 0 or atual [-1] == c:
                if len (atual) == 9:
                    etapas.append (atual)
                    atual = [c]
                else:
                    atual.append (c)
            else:
                etapas.append (atual)
                atual = [c]
        resposta = ""
        if len (atual) > 0: # Para o caso de word vir bazia; LeetCode
            etapas.append (atual)
        for etapa in etapas:
            resposta += chr (len (etapa) + 48)
            resposta += etapa [0] # Qualquer um; são todos iguais
        return resposta
    

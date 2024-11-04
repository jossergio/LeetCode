class Solution:
    def compressedString(self, word: str) -> str:
        resposta = list ()
        atual = list ()
        for c in word:
            if len (atual) == 0 or atual [-1] == c:
                if len (atual) == 9:
                    resposta.append (str (len (atual)) + atual [0])
                    atual = [c]
                else:
                    atual.append (c)
            else:
                resposta.append (str (len (atual)) + atual [0])
                atual = [c]
        if len (atual) > 0: # Para o caso de word vir vazia; LeetCode
            resposta.append (str (len (atual)) + atual [0])
        return "".join (resposta)
    

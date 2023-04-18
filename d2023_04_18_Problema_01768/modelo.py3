class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        resposta = []
        i = 0
        while i < len (word1) and i < len (word2):
            resposta.append (word1 [i])
            resposta.append (word2 [i])
            i += 1
            
            # while também funciona como if
        while i < len (word1):
            resposta.append (word1 [i])
            i += 1
        while i < len (word2):
            resposta.append (word2 [i])
            i += 1
        return "".join (resposta)
    

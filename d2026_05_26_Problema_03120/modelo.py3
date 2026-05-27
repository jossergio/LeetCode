class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        contagem = Counter (word)
        resposta = 0
        for c in range (ord ('A'), ord ('Z') + 1):
            if contagem.get (chr (c), 0) > 0 and contagem.get (chr (c + 32), 0) > 0:
                resposta += 1
        return resposta
        
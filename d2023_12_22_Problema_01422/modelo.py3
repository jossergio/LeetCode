class Solution:
    def maxScore(self, s: str) -> int:
        uns = len ([a for a in s if a == '1']) # Quantitativo inicial
        zeros = 0 # Idem
        resposta = 0
        for c in s [:-1]:
            if c == '1':
                uns -= 1
            else: # Só pode ser 0
                zeros += 1
            resposta = max (resposta, uns + zeros)
        return resposta


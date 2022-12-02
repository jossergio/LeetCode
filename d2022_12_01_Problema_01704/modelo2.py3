class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vogais = "aeiouAEIOU"
        setor1 = 0
        setor2 = 0
        metade = len (s) // 2
        for c in range (0, metade):
            setor1 += 1 if s [c] in vogais else 0
            setor2 += 1 if s [metade + c] in vogais else 0
        return setor1 == setor2
    

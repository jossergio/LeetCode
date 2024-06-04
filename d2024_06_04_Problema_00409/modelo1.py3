class Solution:
    def longestPalindrome(self, s: str) -> int:
        haImpar = False
        contador = 0
        for i in Counter (s).values ():
            contador += (i // 2) * 2 # Divisão inteira; recompõe o par
            haImpar |= (i % 2) == 1 # Independente se já há
        if haImpar:
            contador += 1
        return contador
    

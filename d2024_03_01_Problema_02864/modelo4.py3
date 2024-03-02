class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        lista = sorted (s, reverse = True) # Os 1s vem primeiro
        return "".join (lista [1:] + lista [0:1]) # Pega o primeiro e joga no final
    

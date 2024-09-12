class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        contador = 0
        letras = set (allowed)
        for s in [set (a) for a in words]:
            if s <= letras:
                contador += 1
        return contador
    

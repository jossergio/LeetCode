class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        palavras = list ()
        anterior = 0
        for p in spaces:
            palavras.append (s [anterior:p])
            anterior = p
        palavras.append (s [anterior:]) # Adiciona o que sobrou
        return " ".join (palavras)
    

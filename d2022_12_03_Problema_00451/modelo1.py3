class Solution:
    def frequencySort(self, s: str) -> str:
        ordQtds = sorted ([(c, qtd) for c, qtd in Counter (s).items ()], reverse = True, key = lambda item: item [1]) # Traz ordenado pela quantidade, reversamente
        preparando = list ()
        for c, qtd in ordQtds:
            preparando += [c] * qtd
        return "".join (preparando)
    

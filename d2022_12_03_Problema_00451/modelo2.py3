class Solution:
    def frequencySort(self, s: str) -> str:
        letras = defaultdict (int)
        for c in s:
            letras [c] += 1
        resposta = ""
        for letra, quantidade in sorted ([(c, qtd) for c, qtd in letras.items ()], reverse = True, key = lambda item: item [1]):
            resposta += letra * quantidade # Python
        return resposta
    

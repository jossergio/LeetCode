class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        lista = [(i, q) for i, q in Counter (nums).items ()]
        grupos = set ([b for a, b in lista]) # Pega, só, as quantidades
        resposta = list ()
        for q in sorted (grupos):
            tmp = sorted ([a for a, b in lista if b == q], reverse=True) # Desmembrar, pondo em uma variável, para facilitar a visualização
            for a in tmp:
                resposta.extend ([a] * q)
        return resposta
    

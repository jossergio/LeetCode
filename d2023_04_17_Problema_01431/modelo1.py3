class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maior = sorted (candies, reverse = True) [0] # Tamanho mínimo de candies é 2
        resultado = [False] * len (candies) # Poderia ser True; só para ter um tamanho
        for i, v in enumerate (candies):
            resultado [i] = (v + extraCandies) >= maior
        return resultado
    

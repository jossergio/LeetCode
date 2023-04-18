class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maior = 0
        resultado = [False] * len (candies) # Poderia ser True; spaalterar o if no laço
        vals = defaultdict (list)
        for i, v in enumerate (candies):
            maior = max (maior, v)
            vals [v].append (i)
        for v, i in vals.items (): # Aqui, é invertido
            if v + extraCandies >= maior:
                for j in i:
                    resultado [j] = True
        return resultado
    

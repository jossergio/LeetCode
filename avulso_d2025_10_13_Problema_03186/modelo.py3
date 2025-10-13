class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        valores = sorted (set (power), reverse = True) # Só para ter uma ordem
        contagens = Counter (power) # Para fazer grupos
        t = len (valores)
        memo = dict ()

        def buscar (i: int) -> int:
            if i == t:
                return 0
            # else
            if not i in memo:
                tmp = valores [i] # Só para melhor visualizar o código
                tmp1 = contagens [tmp] * tmp
                tmp2 = buscar (i + 1)
                j = i
                if j != t - 1 and tmp - 2 <= valores [j + 1]:
                    j += 1
                if j != t - 1 and tmp - 2 <= valores [j + 1]: # Preciso fazer isso duas vezes
                    j += 1
                tmp1 += buscar (j + 1)
                memo [i] = max (tmp1, tmp2)
            return memo [i]

        maximo = 0
        for i in range (min (t, 3)): # Só preciso testar três
            maximo = max (maximo, buscar (i))
        return maximo

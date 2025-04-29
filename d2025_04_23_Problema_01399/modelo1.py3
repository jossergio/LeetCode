class Solution:
    def countLargestGroup(self, n: int) -> int:
        
        def soma_digitos (v):
            r = 0
            while v > 0:
                r += v % 10
                v //= 10
            return r

        grupos = defaultdict (int)
        maior = 0
        for v in range (1, n + 1):
            tmp = soma_digitos (v)
            grupos [tmp] += 1
            maior = max (maior, grupos [tmp])
        return len ([v for v in grupos.values () if v == maior])

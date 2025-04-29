class Solution:
    def countLargestGroup(self, n: int) -> int:
        
        def soma_digitos (v):
            r = 0
            while v > 0:
                r += v % 10
                v //= 10
            return r

        grupos = Counter ([soma_digitos (i) for i in range (1, n + 1)])
        maior = max (grupos.values ())
        return len ([c for c in grupos.values () if c == maior])
        
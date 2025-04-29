class Solution:
    def countLargestGroup(self, n: int) -> int:
        
        def soma_digitos (v):
            r = 0
            while v > 0:
                r += v % 10
                v //= 10
            return r

        grupos = sorted (Counter ([soma_digitos (i) for i in range (1, n + 1)]).values (), reverse = True)
        t = len (grupos)
        i = 1
        while i < t and grupos [i] == grupos [0]:
            i += 1
        return i
        
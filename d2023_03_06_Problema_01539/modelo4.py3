class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i = 0 # Apesar de ser 1-begin, o incremento ocorre no início do laço
        t = len (arr)
        indice = 0
        while (k > 0):
            i += 1
            if indice >= t or arr [indice] != i:
                k -= 1
            else:
                indice += 1
        return i
    

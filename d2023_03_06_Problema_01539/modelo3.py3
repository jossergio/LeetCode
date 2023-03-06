class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i = 0 # Apesar de ser 1-begin, o incremento ocorre no início do laço
        arr = arr [::-1] # reversed
        while (k > 0):
            i += 1
            if len (arr) == 0 or arr [-1] != i:
                k -= 1
            else:
                arr.pop ()
        return i
    

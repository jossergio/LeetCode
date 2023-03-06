class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i = 0 # Apesar de ser 1-begin, o incremento ocorre no início do laço
        while (k > 0):
            i += 1
            if len (arr) == 0 or arr [0] != i:
                k -= 1
            else:
                arr.pop (0)
        return i
    

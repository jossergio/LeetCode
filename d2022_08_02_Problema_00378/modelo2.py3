class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        return sorted ([x for linha in matrix for x in linha]) [k - 1]


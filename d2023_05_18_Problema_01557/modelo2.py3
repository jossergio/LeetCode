class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        tmp = set ([x [1] for x in edges])
        return [x for x in range (n) if x not in tmp]
    

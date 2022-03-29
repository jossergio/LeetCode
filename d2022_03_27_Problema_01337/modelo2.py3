class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        contar = list ()
        
        for i, x in enumerate (mat):
            contar.append ([sum (x), i])
            
        contar.sort (key = lambda c: c [0])
        
        return [x [1] for x in contar][:k]


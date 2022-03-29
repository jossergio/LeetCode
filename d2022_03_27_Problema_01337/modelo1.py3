class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        contar = list ()
        
        for i in range (len (mat)):
            contar.append ([mat [i].count (1), i])
            
        contar.sort (key = lambda c: c [0])
        
        return [x [1] for x in contar][:k]


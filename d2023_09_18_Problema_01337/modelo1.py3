class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        contar = list ()
        
        for i, linha in enumerate (mat):
            try:
                contar.append ([linha.index (0), i])
            except:
                contar.append ([len (linha), i])
            
        contar.sort (key = lambda c: (c [0], c [1]))
        
        return [x [1] for x in contar][:k]


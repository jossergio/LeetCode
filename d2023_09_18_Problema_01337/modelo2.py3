class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        contar = dict ()
        
        for i, linha in enumerate (mat):
            try:
                contar [i] = linha.index (0)
            except:
                contar [i] = len (linha)
        
        return [v [0] for v in sorted (contar.items (), key = lambda i: (i [1], i [0]))][:k]


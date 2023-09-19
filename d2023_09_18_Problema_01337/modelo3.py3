class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        
        def pos_0 (lista):
            for i, v in enumerate (lista):
                if (v == 0):
                    return i
            return len (linha)
        
        contar = dict ()
        
        for i, linha in enumerate (mat):
            contar [i] = pos_0 (linha)
        
        return [v [0] for v in sorted (contar.items (), key = lambda i: (i [1], i [0]))][:k]


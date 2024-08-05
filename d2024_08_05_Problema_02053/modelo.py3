class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        tmp = defaultdict (list)
        for i, a in enumerate (arr):
            tmp [a].append (i)
        tmp2 = sorted ([i [0] for a, i in tmp.items () if len (i) == 1])
        k -= 1 # Transforma em 0-begin
        return arr [tmp2 [k]] if k < len (tmp2) else ""
    

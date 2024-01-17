class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        qtds = Counter (arr)
        contagem = set ()
        for q in qtds.values ():
            if q in contagem:
                return False
            else:
                contagem.add (q)
        return True
    

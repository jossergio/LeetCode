class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        lista = defaultdict (list)
        for s in strs:
            lista ["".join (sorted (s))].append (s)
        return lista.values ()
        

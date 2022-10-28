class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        lista = defaultdict (list)
        for s in strs:
            idx = "".join (sorted (s))
            lista [idx].append (s)
        return lista.values ()


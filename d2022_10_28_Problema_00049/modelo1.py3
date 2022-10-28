class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        lista = defaultdict (list)
        for s in strs:
            # Dividi as etapas para facilitar visualização do código
            idx_tmp = sorted ([(i, v) for i, v in Counter (s).items ()])
            idx = reduce (lambda a, b: a + b, [i + str (v) for i, v in idx_tmp], "")
            lista [idx].append (s)
        return [v for v in lista.values ()]


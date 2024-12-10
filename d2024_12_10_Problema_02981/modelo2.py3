class Solution:
    def maximumLength(self, s: str) -> int:
        qtds = defaultdict (int)
        base = ""
        ant = chr (0) # Para ter algo diferente de quaisquer algarismos
        for c in s:
            if c == ant:
                base += c
            else:
                base = str (c)
            t = len (base)
            for i in range (1, t + 1):
                qtds [base [0:i]] += 1
            ant = c
        lista = [len (i) for i, q in qtds.items () if q >= 3]
        return -1 if len (lista) == 0 else max (lista)
    

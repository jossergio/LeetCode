class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        contagem = defaultdict (int)
        for w in words:
            for c, v in Counter (w).items ():
                contagem [c] += v
        t = len (words)
        for v in contagem.values ():
            if v % t != 0:
                return False
        # else
        return True # Passou por tudo e não achou problemas
    

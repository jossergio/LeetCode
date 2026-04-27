class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        t = len (queries [0]) # Todos são do mesmo tamanho
        dt = len (dictionary)
        dc = list ()
        for _ in range (dt):
            dc.append (defaultdict (list))
        resposta = list ()
        for i, d in enumerate (dictionary):
            for j, c in enumerate (d):
                dc [i][c].append (j)
        for q in queries:
            tmp = [t] * dt # Fará contagem regressiva 
            for i, c in enumerate (q):
                for j, d in enumerate (dc):
                    if i in d [c]:
                        tmp [j] -= 1
            if len ([a for a in tmp if a <= 2]) > 0:
                resposta.append (q)
        return resposta

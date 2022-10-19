class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        lista = Counter (words)
        tmp = defaultdict (list)
        for i, v in lista.items ():
            tmp [v].append (i)
            tmp [v].sort ()
        resposta = list ()
        for i in sorted (tmp, reverse = True):
            for v in tmp [i]:
                resposta.append (v)
                k -= 1
                if k == 0:
                    return resposta
        return resposta # Só para ter algo no final e para o caso de k ser maior que len (words)


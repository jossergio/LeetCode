class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        resposta = list ()
        t = len (s)
        palavras = set (wordDict) # Só para transformar
        
        def buscar (p: int, acum: List [str]):
            if p == t:
                resposta.append (" ".join (acum))
            else:
                tmp = "" # string vazia
                for i in range (p, t):
                    tmp += s [i]
                    if (tmp in palavras):
                        acum.append (tmp)
                        buscar (i + 1, acum)
                        acum.pop ()

        acumulado = list ()
        buscar (0, acumulado)
        return resposta


class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        vogais = set (['a', 'e', 'i', 'o', 'u'])

        def consoantes_f (s: str) -> str:
            tmp = ""
            for c in s.lower ():
                if c in vogais:
                    tmp += '.'
                else:
                    tmp += c
            return tmp

        minusculas = [s.lower () for s in wordlist]
        consoantes = [consoantes_f (s) for s in wordlist]
        t = len (wordlist)
        resposta = []
        for s in queries:
            if s in wordlist:
                resposta.append (wordlist [wordlist.index (s)])
                continue
            l = s.lower ()
            if l in minusculas:
                resposta.append (wordlist [minusculas.index (l)])
                continue
            c = consoantes_f (s)
            if c in consoantes:
                resposta.append (wordlist [consoantes.index (c)])
                continue
            resposta.append ("") # Se chegou até aqui
        return resposta

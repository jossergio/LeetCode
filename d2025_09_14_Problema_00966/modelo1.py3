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
            p = -1 # Ainda não encontrou
            capital = -1 # Ainda não encontrou na forma das letras
            vogal = -1 # Ainda não encontrou na forma das vogais
            s_lower = s.lower ()
            s_consoantes_f = consoantes_f (s)
            for i in range (t):
                if s == wordlist [i]:
                    p = i
                    break # Não há melhor
                elif minusculas [i] == s_lower:
                    if capital == -1:
                        capital = i
                elif consoantes [i] == s_consoantes_f:
                    if vogal == -1:
                        vogal = i
            if p > -1: # Achou com base integral
                resposta.append (wordlist [p])
            elif capital > -1: # Achou com base nas letras integrais
                resposta.append (wordlist [capital])
            elif vogal > -1: # Achou com base no padrão de vogais
                resposta.append (wordlist [vogal])
            else: # Adiciona string vazia
                resposta.append ("")
        return resposta

class Solution:
    def sortVowels(self, s: str) -> str:
        vogais = set (['a', 'e', 'i', 'o', 'u'])
        listaVogais = sorted ([ord (c) for c in s if c.lower () in vogais])
        k = 0
        resposta = list ()
        for i in range (len (s)):
            if s [i].lower () in vogais:
                resposta.append (chr (listaVogais [k]))
                k += 1
            else:
                resposta.append (s [i])
        return ''.join (resposta)


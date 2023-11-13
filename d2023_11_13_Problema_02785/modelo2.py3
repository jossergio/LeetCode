class Solution:
    def sortVowels(self, s: str) -> str:
        vogais = set (['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        listaVogais = sorted ([ord (c) for c in s if c in vogais])
        k = 0
        resposta = list ()
        for i in range (len (s)):
            if s [i] in vogais:
                resposta.append (chr (listaVogais [k]))
                k += 1
            else:
                resposta.append (s [i])
        return ''.join (resposta)


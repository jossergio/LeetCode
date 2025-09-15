class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        letras = set (brokenLetters)
        cont = 0
        for p in text.split ():
            tmp = set (p)
            if len (tmp - letras) == len (tmp):
                cont += 1
        return cont

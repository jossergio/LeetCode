class Solution:
    def makeGood(self, s: str) -> str:
        lista = list ()
        for a in range (ord ('a'), ord ('z') + 1):
            lista.append (chr (a) + chr (a - 32))
            lista.append (chr (a - 32) + chr (a))
        while True:
            tirou = False
            for a in lista:
                i = s.find (a)
                if i != -1:
                    tirou = True
                    s = s.replace (a, "")
            if tirou:
                continue
            # else:
            break # Sai do laço principal
        return s # Conterá a string com o resultado
    

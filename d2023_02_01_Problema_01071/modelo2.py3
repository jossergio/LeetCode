class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        t1, t2 = len (str1), len (str2)
        candidato = ""
        letra = 0
        limite = min (len (str1), len (str2))
        while letra < limite and str1 [letra] == str2 [letra]:
            candidato += str1 [letra] # Tanto faz str1 ou str2
            letra += 1
        while len (candidato) > 0 and (t1 % len (candidato) != 0 or t2 % len (candidato) != 0):
            candidato = candidato [:-1]
        if len (candidato) > 0 and (candidato * (t1 // len (candidato)) != str1 or candidato * (t2 // len (candidato)) != str2):
            return "" # Não serviu
        return candidato
    

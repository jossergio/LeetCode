class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        vinculos_s = dict ()
        vinculos_t = dict ()
        for i in range (len (s)): # São do mesmo tamanho
            if s [i] in vinculos_s:
                if vinculos_s [s [i]] != t [i] or t [i] not in vinculos_t or vinculos_t [t [i]] != s [i]:
                    return False
            else: # in vinculos
                if t [i] in vinculos_t:
                    return False # Com certeza, não é o correspondente
                vinculos_s [s [i]] = t [i]
                vinculos_t [t [i]] = s [i]
                
        return True # Passou por todos os testes
    

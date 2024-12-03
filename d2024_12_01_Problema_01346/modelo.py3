class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        dobros = defaultdict (bool)
        for i, c in Counter (arr).items (): # Tira os duplicados e gera contador pro zero
            if i == 0 and c > 1: # Situação interessante
                return True
            if dobros [i] or dobros [i * 2]:
                return True
            if i % 2 == 0: # Se for par...
                dobros [i] = True # ... já inclui como dobro
            dobros [i * 2] = True
        return False # Passou pir todos e não encontrou
    

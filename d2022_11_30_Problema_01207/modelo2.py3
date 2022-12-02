class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr.sort ()
        contar = 1 # len > 1; já conta o 1o
        anterior = arr [0] # Só para já ser definido; varre a Partir do 2o
        contagem = defaultdict (bool)
        for v in arr [1:]: # Começa a comparação pelo 2o
            if v == anterior:
                contar += 1
            else:
                if contagem [contar]:
                    return False
                else:
                    contagem [contar] = True
                    contar = 1
                    anterior = v
        if contagem [contar]: # Fica um resíduo
            return False
        # else
        return True
    

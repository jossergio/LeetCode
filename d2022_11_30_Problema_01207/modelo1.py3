class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr.sort ()
        contar = 0
        anterior = 0 # Só para já ser definido
        contagem = defaultdict (bool)
        for v in arr:
            if contar == 0:
                anterior = v
                contar = 1
            else:
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
    

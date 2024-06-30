class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        diretos = [list () for i in range (n)]
        # Usar [list ()] * n produz ser o mesmo objeto em cada elemento
        for e in edges:
            diretos [e [0]].append (e [1])
        tmp = [set () for i in range (n)] # Idem
        
        def inserir (ascendentes, desc):
            for d in desc:
                for i in ascendentes - tmp [d]:
                    tmp [d].add (i)
                    inserir (tmp [d], diretos [d])
        
        for i in range (n):
            ascendentes = set ([i]) # Já põe o atual
            inserir (ascendentes, diretos [i])
        return [sorted (s) for s in tmp]
    

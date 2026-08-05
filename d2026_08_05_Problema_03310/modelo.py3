class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        grafo = list ()
        for a in range (0, n):
            grafo.append (list ())
        for a in invocations:
            grafo [a [0]].append (a [1])
        
        legitimos = set ([a for a in range (0, n)]) # Inicialmente, pressupõe todos
        def remover (k):
            if k in legitimos:
                legitimos.remove (k)
                for a in grafo [k]:
                    remover (a)

        remover (k)

        def restaurar (k):
            if k not in legitimos:
                legitimos.add (k)
                for a in grafo [k]:
                    restaurar (a)

        # Para a restauração, passa a ser bidirecional
        for a in invocations:
            grafo [a [1]].append (a [0])
        base = set (legitimos) # Pois legitimos mudara durante o laço abaixo
        for a in base:
            for b in grafo [a]:
                restaurar (b)
        return list (legitimos)

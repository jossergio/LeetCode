class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        tsalas = len (rooms)
        fila = [a for a in rooms [0]] # A fila inicia com essas chaves
        visitados = set ([0]) # Já coloca a primeira casa como visitado
        while len (fila) > 0 and len (visitados) != tsalas:
            proximo = fila.pop (0)
            if not proximo in visitados:
                visitados.add (proximo)
                fila.extend (rooms [proximo])
        return len (visitados) == tsalas
    

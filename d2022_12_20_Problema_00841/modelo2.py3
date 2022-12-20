class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        tsalas = len (rooms)
        fila = rooms [0].copy () # A fila inicia com essas chaves
        visitados = set ([0]) # Já coloca a primeira casa como visitado
        while len (fila) > 0 and len (visitados) != tsalas:
            proximo = fila.pop (0)
            visitados.add (proximo)
            fila.extend ([a for a in rooms [proximo] if a not in visitados])
        return len (visitados) == tsalas
    

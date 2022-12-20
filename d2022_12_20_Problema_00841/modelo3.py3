class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        tsalas = len (rooms)
        pilha = rooms [0].copy () # A fila inicia com essas chaves
        visitados = [False] * tsalas
        visitados [0] = True # Já coloca a primeira casa como visitado
        while len (pilha) > 0:
            proximo = pilha.pop ()
            visitados [proximo] = True
            pilha.extend ([a for a in rooms [proximo] if not visitados [a]])
        return all (visitados)
    

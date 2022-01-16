class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        distancias = list ()
        ultimo = -1
        for i, v in enumerate (seats):
            if v == 1:
                distancia = i - ultimo
                if ultimo == -1:
                    distancias.append (i)
                else:
                    distancias.append (distancia // 2)
                ultimo = i
        # Sempre teremos 0, caso no 1o haja uma pessoa
        # Se ultimo não for o último, acrescenta
        if ultimo != len (seats) - 1:
            distancia = len (seats) - 1 - ultimo
            distancias.append (distancia)
        distancias.sort (reverse = True)
        return distancias [0]


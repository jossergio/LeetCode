class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        maximo = 0
        ultimo = -1
        for i, v in enumerate (seats):
            if v == 1:
                distancia = i - ultimo
                if ultimo == -1:
                    maximo = i
                else:
                    maximo = max (maximo, distancia // 2)
                ultimo = i
        # Sempre teremos 0, caso no 1o haja uma pessoa
        # Se ultimo não for o último, acrescenta
        if ultimo != len (seats) - 1:
            distancia = len (seats) - 1 - ultimo
            maximo = max (maximo, distancia)
        
        return maximo


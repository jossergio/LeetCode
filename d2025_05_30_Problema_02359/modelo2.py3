class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n1 = set ([node1])
        nn1 = {node1: 0}
        c = 0
        prox = edges [node1]
        while prox != -1 and prox not in n1:
            c += 1
            n1.add (prox)
            nn1 [prox] = c
            prox = edges [prox]
        n2 = set ([node2])
        nn2 = {node2: 0}
        c = 0
        prox = edges [node2]
        while prox != -1 and prox not in n2:
            c += 1
            n2.add (prox)
            nn2 [prox] = c
            prox = edges [prox]
        minimo = -1 # Por padrão; também será índice de comparação
        resposta = -1 # Só para ter algum valor aqui
        for i in sorted (n1 & n2):
            tmp = max (nn1 [i], nn2 [i])
            if resposta == -1 or tmp < minimo:
                minimo = tmp
                resposta = i
        return resposta

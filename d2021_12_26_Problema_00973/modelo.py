class Solution(object):
    def chave (self, elemento):
        return elemento [0]
        
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        tmp = list () # Conterá os valores das somas das potências
        # Não precisa calcular a raiz quadrada! Soma maior, valor maior
        # O resultado deverá ser ordenado com base nesse valor
        for ponto in points:
            tmp.append ([ponto [0] * ponto [0] + ponto [1] * ponto [1], ponto [0], ponto [1]])
        tmp.sort (key = self.chave)
        tmp = tmp [0:k]
        resposta = list ()
        for t in tmp:
            resposta.append ([t [1], t [2]])
        return resposta [0:k]


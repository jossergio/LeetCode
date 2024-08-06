class Solution:
    def minimumPushes(self, word: str) -> int:
        ordem = sorted ([(c, q) for c, q in Counter (word).items ()], key = lambda a: a [1], reverse = True)
        '''Para melhor visualiação, criei a variável acima no lugar de utilizar
        o resultado diretamente no laço.'''
        tecla = 2 # Vou seguir conforme a numeração
        nivel = 1
        resposta = 0
        for _, v in ordem:
            if tecla > 9:
                tecla = 2
                nivel += 1
            resposta += v * nivel
            tecla += 1
        return resposta


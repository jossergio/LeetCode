class Solution:
    def minimumPushes(self, word: str) -> int:
        ordem = sorted ([q for q in Counter (word).values ()], reverse = True)
        '''Para melhor visualiação, criei a variável acima no lugar de utilizar
        o resultado diretamente no laço.'''
        tecla = 2 # Vou seguir conforme a numeração
        nivel = 1
        resposta = 0
        for v in ordem:
            if tecla > 9:
                tecla = 2
                nivel += 1
            resposta += v * nivel
            tecla += 1
        return resposta

